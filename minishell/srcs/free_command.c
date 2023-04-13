/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/12 12:12:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_redirect(void *content)
{
	t_redirect *redirect;

	if (!content)
		return ;
	redirect = (t_redirect *)content;
	free(redirect->file);
	if (redirect->fd != 1 && redirect->fd != -1)
			close(redirect->fd);
	free(redirect);
}

void	free_command(void *content)
{
	t_command *cmd;

	if (!content)
		return ;
	cmd = (t_command *)content;
	ft_lstclear(&cmd->redirects, free_redirect);
	ft_free_tab(cmd->args);
	free(cmd);
}

void	free_commands(t_list **commands)
{
	if (!commands || !*commands)
		return ;
	ft_lstclear(commands, free_command);
}
