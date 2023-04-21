/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/21 18:30:29 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
void	quit_properly(t_list *commands, char *pathname)
{
	free(pathname);
	free_commands(commands);
	ft_lstclear(&g_minishell.envs, free_env);
	exit(g_minishell.exit_status);
}

int	execute_command(t_list *commands,
	char *pathname, char **args, int fd_io[2], int fd_in)
{
	char	**envp;
	int		pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		//si les fd pas valides on quitte le processus
		if (fd_io[0] == -1 || fd_io[1] == -1)
			quit_properly(commands, pathname);
		//redir l'input et l'output selon fd_io
		redirect_input_output(fd_io, fd_in);
		//converti la lst chainee envs en un tableau d envp
		envp = list_to_tab(g_minishell.envs);
		execve(pathname, args, envp);
		ft_free_tab(envp);
		quit_properly(commands, pathname);
	}
	//ferme les fd inutiles pour le processus parent
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	return (pid);
}
