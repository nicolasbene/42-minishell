/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/03 21:19:02 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	exec(char *pathname, char **args, char **envp, int fd_rw[2], int fdin)
{
	int	pid;
	
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (fd_rw[0] == -1 || fd_rw[1] == -1)
			exit(12);
		piping(fd_rw, fdin);
		execve(pathname, args, envp);
	}
	if (fd_rw[0] != -1)
		close(fd_rw[0]);
	if (fd_rw[1] != -1)
		close(fd_rw[1]);
	return (pid);
}
