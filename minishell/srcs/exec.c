/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:45:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/04 17:47:27 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	piping(int fd_io[2], int fdin)
{
	dup2(fd_io[0], STDIN_FILENO);
	dup2(fd_io[1], STDOUT_FILENO);
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	if (fdin != -1)
		close(fdin);
}

int	exec(char *pathname, char **args, char **envp, int fd_io[2], int fdin)
{
	int	pid;
	
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (fd_io[0] == -1 || fd_io[1] == -1)
			exit(1111);
		piping(fd_io, fdin);
		execve(pathname, args, envp);
	}
	if (fd_io[0] != -1)
		close(fd_io[0]);
	if (fd_io[1] != -1)
		close(fd_io[1]);
	return (pid);
}
