/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:04:56 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/26 15:22:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	ft_rdlstokenadd_back(t_rdlist **lst, t_rdlist *new)
{
	t_rdlist	*tmp;

	if (lst && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (lst && *lst == NULL)
		*lst = new;
}

// new == NULL, pour proteger en cas de fail de malloc
void	ft_cmdlstokenadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (lst && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (lst && *lst == NULL)
		*lst = new;
}