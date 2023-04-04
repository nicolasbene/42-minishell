/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/04 17:27:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nbr_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	handle_redirects(int fd_io[2], int fd_pipe[2], int next, t_list *commands)
{
	fd_io[0] = redir_input(fd_pipe[0], commands);
	if (next)
	{
		if (pipe(fd_pipe) == -1)
			return (-1);
		fd_io[1] = redir_output(fd_pipe[1], commands);
	}
	else
		fd_io[1] = redir_output(dup(STDOUT_FILENO), commands);
	dprintf(2, "fd_io[0] = %d fd_io[1] = %d\n", fd_io[0], fd_io[1]);
	return (0);
}

int	forks(t_list *commands, char **envp, int fd_io[2], int fd_pipe[2])
{
	t_command	*cmd;
	char		*pathname;
	int			last_pid;

	last_pid = 0;

	while (commands)
	{
		cmd = commands->content;
		handle_redirects(fd_io, fd_pipe, commands->next != NULL, commands);
		
		pathname = file_to_execute(cmd->args[0], envp);
		last_pid = exec(pathname, cmd->args, envp, fd_io, fd_pipe[0]);
		free(pathname);
		commands = commands->next;
	}
	return (last_pid);
}

int	pipex(t_list *commands, char **envp)
{
	int			last_pid;
	int			fd_pipe[2];
	int			fd_io[2];

	last_pid = 0;
	fd_pipe[0] = dup(STDIN_FILENO);
	dprintf(1, "fd_pipe[0] = %d\n", fd_pipe[0]);
	fd_pipe[1] = -1;


	last_pid = forks(commands, envp, fd_io, fd_pipe);
	dprintf(2, "last_pid = %d\n", last_pid);

	return (0);
}
