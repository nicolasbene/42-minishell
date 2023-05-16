/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/16 17:20:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	free_tab(char **tab)
{
	int	i;

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

void	free_rdlist(t_rdlist *rdlist)
{
	t_rdlist	*tmp;

	while (rdlist)
	{
		tmp = rdlist;
		rdlist = rdlist->next;
		free(tmp->str);
		free(tmp);
	}
}

void	free_commands(t_cmd *commands)
{
	t_cmd	*tmp;

	if (!commands || commands == NULL)
		return ;
	while (commands)
	{
		tmp = commands;
		commands = commands->next;
		if (tmp->rd != NULL)
			free_rdlist(tmp->rd);
		if (tmp->arg != NULL)
			free_tab(tmp->arg);
		free(tmp);
	}
}


