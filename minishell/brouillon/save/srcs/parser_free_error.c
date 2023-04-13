/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:27:12 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/05 11:02:15 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_free_cmd(t_cmd **lst)
{
	t_cmd	*aux;
	t_cmd	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		if (aux->arg != NULL)
			free(aux->arg);
		if (aux->rd)
			ft_rdlstclear(&aux->rd);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

void	ft_rdlstclear(t_rdlist **lst)
{
	t_rdlist	*aux;
	t_rdlist	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

// erreur malloc sur cmd
void	ft_free_list(t_cmd **cmd, t_mst **mst)
{
	if (*mst != NULL)
		ft_mslstokenclear(mst);
	if (*cmd != NULL)
		ft_free_cmd(cmd);
}
