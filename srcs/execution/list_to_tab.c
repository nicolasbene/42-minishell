/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:04 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/27 11:30:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_lst_size(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**list_to_tab(t_env *lst)
{
	int		i;
	t_env	*env;
	char	*s;
	char	*tmp;
	char	**tab;

	i = 0;
	tab = malloc((ft_lst_size(lst) + 1) * sizeof(*tab));
	if (!tab)
		exit(12);
	while (lst)
	{
		env = lst;
		tmp = ft_strjoin(env->name, "=");
		s = ft_strjoin(tmp, env->content);
		free(tmp);
		tab[i++] = s;
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
