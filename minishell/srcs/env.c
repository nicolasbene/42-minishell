/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/07 17:44:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_node_env(char *av)
{
	t_env	*node_env;
	int		i;

	node_env = malloc(sizeof(*node_env));
	i = 0;
	while (av[i] != '=')
		i++;
	node_env->name = ft_substr(av, 0, i);
	node_env->value = ft_substr(av, i + 1, ft_strlen(av) - i);

	return (node_env);
}

t_list	*add_node_env(t_list *lst_env, char *av)
{
	t_list	*lst_new;
	t_env	*node_env;
	
	node_env = create_node_env(av);
	
	lst_new= ft_lstnew(node_env);
	ft_lstadd_back(&lst_env, lst_new);

	return (lst_env);
}

t_list	*tab_to_list(char **envp)
{
	t_list	*lst_env;
	int		i;

	lst_env = NULL;
	i = 0;
	while (envp[i])
	{
		lst_env = add_node_env(lst_env, envp[i]);
		i++;
	}
	return (lst_env);
}