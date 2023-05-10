/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/10 11:35:38 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	redirect_input_output(int fd_io[2], int fd_in)
{
	//redir l'input std et l'output std selon les fd
	dup2(fd_io[0], STDIN_FILENO);
	dup2(fd_io[1], STDOUT_FILENO);
	//ferme les fd inutiles pour lenfant
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	if (fd_in != -1)
		close(fd_in);
}

//free et quitte le processus
void	quit_properly(t_cmd *commands, char *pathname)
{
	free(pathname);
	free_commands(commands);
	free_envs(&g_minishell.envs);
	exit(g_minishell.exit_status);
}

static void	exit_error(t_cmd *commands, const char *format, const char *s, int code, char *pathname)
{
	print_error(format, s, NULL);
	free_envs(&g_minishell.envs);
	free_commands(commands);
	if (pathname)
		free(pathname);
	exit(code);
}

/*execute une commande en verifiant que le pathname existe et quon a la permission de lexecuter
ensuite elle verifie si c un built-in et si c le cas l'execute */
void	exec_or_error(t_cmd *commands, char *pathname, char **args)
{
	char		**envp;
	struct stat	buf;

	//verifie si le pathname et les arguments sont valides
	if (pathname == NULL || ft_strlen(args[0]) == 0)
		exit_error(commands, "%s: command not found", args[0], 127, pathname);

	//verifie si le pathname pointe vers un repo
	if (stat(pathname, &buf) != -1)
	{
		if (S_ISDIR(buf.st_mode))
			exit_error(commands,"%s: Is a directory", args[0], 126, pathname);
	}
	//verifie si le pathname existe et si on a la permission
	if (access(pathname, F_OK) == -1 && (ft_strncmp(args[0], "./", 2) == 0
			|| ft_strncmp(args[0], "../", 2) == 0
			|| ft_strncmp(args[0], "/", 1) == 0))
		exit_error(commands, "%s: No such file or directory", args[0], 127, pathname);
	if (builtins(nbr_args(args), commands) == 0) // ici t_cmd
		free_envs(&g_minishell.envs);
	else
	{
		//converti la lst chainee envs en un tableau d envp
		envp = list_to_tab(g_minishell.envs);
		//tente d executer la commande
		execve(pathname, args, envp);
		ft_free_tab(envp);
		exit_error(commands, "%s: Permission denied", pathname, 126, pathname);
	}
}

void	close_save_std(void)
{
	close(3);
	close(4);
}

int	execute_command(t_cmd *commands,
	char *pathname, char **args, int fd_io[2], int fd_in)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		close_save_std();
		//si les fd sont pas valides on quitte le processus
		if (fd_io[0] == -1 || fd_io[1] == -1)
			quit_properly(commands, pathname);
		//redir l'input et l'output selon fd_io
		redirect_input_output(fd_io, fd_in);
		exec_or_error(commands, pathname, args);
		quit_properly(commands, pathname);
	}
	//ferme les fd inutiles pour le processus parent
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	return (pid);
}
