/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/11 10:31:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

static void	exit_error(t_cmd *commands, const char *format, const char *s, int code, char *pathname)
{
	print_error(format, s, NULL);
	free_commands(commands);
	free_envs(&g_minishell.envs);
	if (pathname)
		free(pathname);
	exit(code);
}

void	exec_or_error(t_cmd *commands, char *pathname, char **args)
{
	char		**envp;
	struct stat	buf;

	if (pathname == NULL || ft_strlen(args[0]) == 0)
		exit_error(commands, "%s: command not found", args[0], 127, pathname);
	if (stat(pathname, &buf) != -1)
	{
		if (S_ISDIR(buf.st_mode))
			exit_error(commands,"%s: Is a directory", args[0], 126, pathname);
	}
	if (access(pathname, F_OK) == -1 && (ft_strncmp(args[0], "./", 2) == 0
			|| ft_strncmp(args[0], "../", 2) == 0
			|| ft_strncmp(args[0], "/", 1) == 0))
		exit_error(commands, "%s: No such file or directory", args[0], 127, pathname);
	if (builtins(nbr_args(args), commands) == 0)
		free_envs(&g_minishell.envs);
	else
	{
		envp = list_to_tab(g_minishell.envs);
		execve(pathname, args, envp);
		free_tab(envp);
		exit_error(commands, "%s: Permission denied", pathname, 126, pathname);
	}
}

void	redirect_input_output(int fd_io[2], int fd_in)
{
	dup2(fd_io[0], STDIN_FILENO);
	dup2(fd_io[1], STDOUT_FILENO);
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	if (fd_in != -1)
		close(fd_in);
}

void	quit_properly(t_cmd *commands, char *pathname)
{
	free(pathname);
	free_commands(commands);
	free_envs(&g_minishell.envs);
	exit(g_minishell.exit_status);
}

int	execute_command(t_cmd *commands,
	char *pathname, t_cmd *tmp_commands, int fd_io[2], int fd_in)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		close_save_std();
		if (fd_io[0] == -1 || fd_io[1] == -1)
			quit_properly(commands, pathname);
		redirect_input_output(fd_io, fd_in);
		exec_or_error(commands, pathname, tmp_commands->arg);
		quit_properly(commands, pathname);
	}
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	return (pid);
}
