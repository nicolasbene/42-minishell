/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/11 09:29:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	open_and_dup_input(t_cmd *cmd, int fd_in)
{
	t_rdlist	*redirects_lst;
	int			redirect_fd;

	redirects_lst = cmd->rd;
	while (redirects_lst != NULL)
	{
		if (redirects_lst->type == RD_INF
			|| redirects_lst->type == RD_HERE)
		{
			redirect_fd = open_fd(redirects_lst->type, redirects_lst->str);
			fd_in = dup(redirect_fd);
			if (redirect_fd != 1 && redirect_fd != -1)
				close(redirect_fd);
			if (fd_in == -1)
				return (-1);
		}
		redirects_lst = redirects_lst->next;
	}
	return (fd_in);
}

int	redir_input(t_cmd *cmd, int fd_in)
{
	if (fd_in == -1)
		return (-1);
	fd_in = open_and_dup_input(cmd, fd_in);
	if (fd_in == -1)
		return (-1);
	return (fd_in);
}

int	open_and_dup2_output(t_cmd *cmd, int fd_out)
{
	t_rdlist	*redirects_lst;
	int			redirect_fd;

	redirects_lst = cmd->rd;
	while (redirects_lst != NULL)
	{
		if (redirects_lst->type == RD_OUT
			|| redirects_lst->type == RD_APP)
		{
			redirect_fd = open_fd(redirects_lst->type, redirects_lst->str);
			dup2(redirect_fd, fd_out);
			if (redirect_fd != -1)
				close(redirect_fd);
		}
		redirects_lst = redirects_lst->next;
	}
	return (fd_out);
}

int	redir_output(t_cmd *cmd, int fd_out)
{
	int			last_fd;

	last_fd = 0;
	if (fd_out == -1)
		return (-1);
	fd_out = open_and_dup2_output(cmd, fd_out);
	if (fd_out == -1)
		return (close(fd_out), -1);
	return (fd_out);
}

int	handle_redirects(int fd_io[2], int fd_pipe[2], int next, t_cmd	*cmd)
{
	fd_io[0] = redir_input(cmd, fd_pipe[0]);
	if (next)
	{
		if (pipe(fd_pipe) == -1)
			return (-1);
		fd_io[1] = redir_output(cmd, fd_pipe[1]);
	}
	else
		fd_io[1] = redir_output(cmd, dup(STDOUT_FILENO));
	return (0);
}
