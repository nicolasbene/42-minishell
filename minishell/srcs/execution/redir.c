/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/15 19:22:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_input2(t_command *cmd, int fdin)
{
	t_redirect	*redirect;
	t_list		*tmp_rd;
	int			fd_redirect;

	tmp_rd = cmd->redirects;
	while (tmp_rd != NULL)
	{
		redirect = tmp_rd->content;
		if (redirect->type == RD_IN
			|| redirect->type == RD_HEREDOC)
		{
			fd_redirect = open_fd(redirect->type, redirect->file);
			fdin = dup(fd_redirect);
			if (fd_redirect != 1 && fd_redirect != -1)
				close(fd_redirect);
			if (fdin == -1)
				return (-1);
		}
		tmp_rd = tmp_rd->next;
	}
	return (fdin);
}

int	redir_input(int fdin, t_list *commands)
{
	t_command	*cmd;

	if (fdin == -1)
		return (-1);
	cmd = commands->content;
	fdin = redir_input2(cmd, fdin);
	if (fdin == -1)
		return (-1);
	return (fdin);
}

int	redir_output2(t_command *cmd, int fdout, int *last_fd)
{
	t_redirect	*redirect;
	t_list		*tmp_rd;
	int			fd_redirect;

	tmp_rd = cmd->redirects;
	while (tmp_rd != NULL)
	{
		redirect = tmp_rd->content;
		if (redirect->type == RD_OUT
			|| redirect->type == RD_APPEND)
		{
			fd_redirect = open_fd(redirect->type, redirect->file);
			dup2(fd_redirect, fdout);
			*last_fd = fd_redirect;
			if (fd_redirect != 1 && fd_redirect != -1)
				close(fd_redirect);
			dprintf(2, "last_fd = %d\n", *last_fd);
		}
		tmp_rd = tmp_rd->next;
	}
	return (fdout);
}

int	redir_output(int fdout, t_list *commands)
{
	t_command	*cmd;
	int			last_fd;

	last_fd = 0;
	dprintf(2, "FDOUT : %d\n", fdout);
	if (fdout == -1)
		return (-1);
	cmd = commands->content;
	fdout = redir_output2(cmd, fdout, &last_fd);
	if (last_fd == -1)
		return (close(fdout), -1);
	return (fdout);
}
