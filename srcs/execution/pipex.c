/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/19 12:24:28 by nibenoit         ###   ########.fr       */
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

int	forks(t_cmd *cmd, int fd_io[2], int fd_pipe[2])
{
	char		*pathname;
	int			last_pid;

	last_pid = 0;
	while (cmd)
	{
		ft_variable_exp(cmd, g_minishell.envs);
		ft_quote_mngt(cmd);
		handle_redirects(fd_io, fd_pipe, cmd->next != NULL, cmd);
		if (cmd->arg[0] == 0)
			break ;
		if (cmd->arg == NULL)
			pathname = ft_strdup("");
		else
			pathname = file_to_execute(cmd->arg[0]);
		last_pid = execute_command(cmd->arg, pathname, fd_io, fd_pipe[0]);
		free(pathname);
		cmd = cmd->next;
	}
	return (last_pid);
}

int	pipex(t_cmd *cmd)
{
	int			last_pid;
	int			fd_pipe[2];
	int			fd_io[2];

	last_pid = 0;
	fd_pipe[0] = dup(STDIN_FILENO);
	fd_pipe[1] = -1;
	if (cmd->arg && cmd->next == NULL && ifbuiltins(cmd->arg) == 0)
	{
		ft_variable_exp(cmd, g_minishell.envs);
		ft_quote_mngt(cmd);
		handle_redirects(fd_io, fd_pipe, cmd->next != NULL, cmd);
		builtins_parent(nbr_args(cmd->arg), cmd->arg, fd_io, fd_pipe[0]);
	}
	else
		last_pid = forks(cmd, fd_io, fd_pipe);
	return (last_pid);
}
