/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/15 19:30:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_minishell;

void	piping(int fd_rw[2], int fdin)
{
	dup2(fd_rw[0], STDIN_FILENO);
	dup2(fd_rw[1], STDOUT_FILENO);
	if (fd_rw[0] != -1)
		close(fd_rw[0]);
	if (fd_rw[1] != -1)
		close(fd_rw[1]);
	if (fdin != -1)
		close(fdin);
}

void	quit_properly(t_list *commands, char *pathname)
{
	free(pathname);
	free_commands(commands);
	ft_lstclear(&g_minishell.envs, free_env);
	exit(g_minishell.exit_status);
}

int	execute_command(t_list *commands,
	char *pathname, char **args, int fd_rw[2], int fdin)
{
	char	**envp;
	int		pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (fd_rw[0] == -1 || fd_rw[1] == -1)
			quit_properly(commands, pathname);
		piping(fd_rw, fdin);
		envp = list_to_tab(g_minishell.envs);
		execve(pathname, args, envp);
		ft_free_tab(envp);
		quit_properly(commands, pathname);
	}
	if (fd_rw[0] != -1)
		close(fd_rw[0]);
	if (fd_rw[1] != -1)
		close(fd_rw[1]);
	return (pid);
}
