/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:58:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/09 10:58:49 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pslstsize(t_stack *lst)
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
