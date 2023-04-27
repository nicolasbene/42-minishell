/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/26 15:23:04 by nibenoit         ###   ########.fr       */
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
			// duplique le fd du fichier ouvert dans fd_out
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

//gestion des redirections dentree et sortie et des pipes potentielles
int	handle_redirects(int fd_io[2], int fd_pipe[2], int next, t_cmd	*cmd)
{
	//rd de lentree std avec la commande actuelle
	fd_io[0] = redir_input(cmd, fd_pipe[0]);
	if (next)
	{
		//creation du pipe et maj des fd du pipe
		if (pipe(fd_pipe) == -1)
			return (-1);
		//rd de la sortie de la cmd actuelle vers le pipe
		fd_io[1] = redir_output(cmd, fd_pipe[1]);
	}
	else
		//si c la dernier commnde on redirige sa sortie vers la sortie std
		fd_io[1] = redir_output(cmd, dup(STDOUT_FILENO));
	return (0);
}
