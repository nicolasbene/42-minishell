/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:39:34 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/18 19:44:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	heredoc_readlines(const char *stop, int fd)
{
	char	*line;

	line = readinput("> ");
	while (line && ft_strcmp(line, stop) != 0)
	{
		ft_putendl_fd(line, fd);
		line = readinput("> ");
	}
	if (line)
		free(line);
}

int	handle_heredoc_notty(const char *stop)
{
	int		fd[2];

	if (pipe(fd) == -1)
		return (-1);
	heredoc_readlines(stop, fd[1]);
	close(fd[1]);
	return (fd[0]);
}

int	handle_heredoc_fork(const char *stop)
{
	int		fd[2];
	int		pid;
	int		status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (!pid)
	{
		reset_signals();
		close(fd[0]);
		handle_signals_heredoc_child();
		heredoc_readlines(stop, fd[1]);
		close(fd[1]);
		exit(0);
	}
	close(fd[1]);
	wait(&status);
	handle_signals();
	if (status == SIGINT)
		return (close(fd[0]), -1);
	handle_signals_heredoc();
	return (fd[0]);
}

int	handle_heredoc(const char *stop)
{
	if (!isatty(STDIN_FILENO))
		return (handle_heredoc_notty(stop));
	return (handle_heredoc_fork(stop));
}
