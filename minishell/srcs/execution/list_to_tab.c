/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:04 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/12 10:31:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_tab(t_list *lst)
{
	int		i;
	t_env	*env;
	char	*s;
	char	*tmp;
	char	**tab;

	i = 0;
	tab = malloc((ft_lstsize(lst) + 1) * sizeof(*tab));
	if (!tab)
		exit(12);
	while (lst)
	{
		env = lst->content;
		tmp = ft_strjoin(env->name, "=");
		s = ft_strjoin(tmp, env->value);
		free(tmp);
		tab[i++] = s;
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
