/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/03 21:14:48 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_file(t_command *cmd, int fdin)
{
	t_redirect	*redirect;
	t_list		*tmp_rd;

	tmp_rd = cmd->redirects;
	while (tmp_rd != NULL)
	{
		redirect = tmp_rd->content;
		if (redirect->type == RD_IN
			|| redirect->type == RD_HEREDOC)
		{
			fdin = dup(redirect->fd);
			if (fdin == -1)
				return (-1);
		}
		tmp_rd = tmp_rd->next;
	}

	return (fdin);
}

int redir_input(int fdin, t_list *commands)
{
	t_command	*cmd;

	if (fdin == -1)
		return (-1);
	cmd = commands->content;
	fdin = redir_file(cmd, fdin);
	dprintf(2, "fdin : %d\n", fdin);

	if (fdin == -1)
		return (-1);
	return (fdin);
}

int	redir_output(int fdout, t_list *commands)
{
	int			last_fd;
	t_command	*cmd;
	t_redirect	*redirect;
	t_list		*tmp_rd;

	last_fd = 0;
	if (fdout == -1)
		return (-1);
	cmd = commands->content;
	tmp_rd = cmd->redirects;
	while (tmp_rd != NULL)
	{
		redirect = tmp_rd->content;
		if (redirect->type == RD_OUT
			|| redirect->type == RD_APPEND)
		{
			dup2(redirect->fd, fdout);
			last_fd = redirect->fd;
			dprintf(2, "last_fd = %d\n", last_fd);
		}
		tmp_rd = tmp_rd->next;
	}
	if (last_fd == -1)
		return (close(fdout), -1);
	return (fdout);
}