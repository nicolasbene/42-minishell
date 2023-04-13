/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:31:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/13 22:58:27 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

void	save_std(int *fd_input, int *fd_output)
{
	*fd_input = dup(STDIN_FILENO);
	*fd_output = dup(STDOUT_FILENO);
}

void	reset_std(int fd_input, int fd_output)
{
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_input);
	close(fd_output);
}

int	executing(t_list *commands)
{
	int	fd_input;
	int	fd_output;
	int last_pid;

	save_std(&fd_input, &fd_output);
	last_pid = pipex(commands);
	reset_std(fd_input, fd_output);
	if (last_pid == -1)
		return (-1);
	
	//wait_pid
	while (wait(NULL) != -1)
		;
	//gestion des signaux et du status
	return (0);
}