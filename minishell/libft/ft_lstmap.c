/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:04:29 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/15 20:45:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	if (lst)
	{
		tmp = lst;
		start = ft_lstnew((*f)(tmp->content));
		if (start == NULL)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew((*f)(tmp->content));
			if (new == NULL)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
			ft_lstadd_back(&start, new);
			tmp = tmp->next;
		}
		return (start);
	}
	return (NULL);
}
