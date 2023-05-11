/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/11 09:23:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	nbr_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	forks(t_cmd *commands, int fd_io[2], int fd_pipe[2])
{
	t_cmd		*tmp_commands;
	char		*pathname;
	int			last_pid;

	last_pid = 0;
	tmp_commands = commands;
	while (tmp_commands)
	{
		handle_redirects(fd_io, fd_pipe,
			tmp_commands->next != NULL, tmp_commands);
		ft_variable_exp(tmp_commands, g_minishell.envs);
		pathname = file_to_execute(tmp_commands->arg[0]);
		last_pid = execute_command(commands, pathname, tmp_commands,
				fd_io, fd_pipe[0]);
		free(pathname);
		tmp_commands = tmp_commands->next;
	}
	return (last_pid);
}

int	pipex(t_cmd *commands)
{
	int			last_pid;
	int			fd_pipe[2];
	int			fd_io[2];

	last_pid = 0;
	fd_pipe[0] = dup(STDIN_FILENO);
	fd_pipe[1] = -1;
	if (commands->arg && commands->next == NULL
		&& ifbuiltins(commands->arg) == 0)
	{
		ft_variable_exp(commands, g_minishell.envs);
		handle_redirects(fd_io, fd_pipe, commands->next != NULL, commands);
		builtins_parent(nbr_args(commands->arg), commands, fd_io, fd_pipe[0]);
	}
	else
		last_pid = forks(commands, fd_io, fd_pipe);
	return (last_pid);
}
