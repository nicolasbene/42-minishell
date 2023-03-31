/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:54:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/30 14:06:00 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"

t_mst	*ft_init_token(char *value, int type)
{
	t_mst	*new;

	new = (t_mst *)malloc(sizeof(t_mst) * 1);
	if (new == NULL)
		return (NULL);
	else
	{
		new->value = value;
		new->type = type;
	}
	new->next = NULL;
	return (new);
}

void	ft_mslstokenclear(t_mst **lst)
{
	t_mst	*aux;
	t_mst	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		if (aux->type == TOKEN_WORD)
			free(aux->value);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

void	ft_mslstokenadd_back(t_mst **lst, t_mst *new)
{
	t_mst	*tmp;

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

t_mst	*ft_msltokenlast(t_mst *lst)
{
	if (lst == NULL)
		return (NULL);
	else
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

int	ft_mslstokensize(t_mst *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	else
	{
		while (lst->next != NULL)
		{
				lst = lst->next;
				i++;
		}
	}
	return (i + 1);
}
