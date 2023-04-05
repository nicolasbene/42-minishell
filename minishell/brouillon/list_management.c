/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:11:59 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/05 11:38:02 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_pslstnew(int newnbr, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = newnbr;
	new->i = index;
	new ->next = NULL;
	new ->prev = NULL;
	return (new);
}

void	ft_pslstclear(t_stack **lst)
{
	t_stack	*aux;
	t_stack	*temp;

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

void	ft_pslstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	if (lst && *lst == NULL)
		*lst = new;
}

t_stack	*ft_pslstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	else
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

void	ft_psavantlstlast(t_stack **lst)
{
	if ((*lst) == NULL)
		return ;
	else
		while ((*lst)->next->next != NULL)
			(*lst) = (*lst)->next;
}



((*mst)->type == TOKEN_G || (*mst)->type == TOKEN_GG
			|| (*mst)->type == TOKEN_L || (*mst)->type == TOKEN_LL)