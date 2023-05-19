/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:50 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/19 11:57:48 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

t_env	*get_env_var(t_env *envs, const char *name)
{
	while (envs)
	{
		if (ft_strcmp(envs->name, name) == 0)
			return (envs);
		envs = envs->next;
	}
	return (NULL);
}

t_env	*replace_env_var(t_env *envs, const char *name, const char *new_content)
{
	t_env	*node;

	node = get_env_var(envs, name);
	if (node)
	{
		free(node->content);
		free(node->name);
		node->name = ft_strdup(name);
		node->content = ft_strdup(new_content);
		return (envs);
	}
	return (NULL);
}

t_env	*create_node_env(char *av)
{
	t_env	*node_env;
	int		i;

	node_env = malloc(sizeof(*node_env));
	if (!node_env)
		return (NULL);
	i = 0;
	while (av[i] != '=')
		i++;
	node_env->name = ft_substr(av, 0, i);
	if (node_env->name == NULL)
		return (free(node_env), NULL);
	node_env->content = ft_substr(av, i + 1, ft_strlen(av) - i);
	if (node_env->content == NULL)
		return (free(node_env->name), free(node_env), NULL);
	node_env->next = NULL;
	return (node_env);
}

t_env	*add_env_back(t_env *envs, t_env *node_env)
{
	t_env	*tmp;
	t_env	*replace;

	tmp = envs;
	if (!envs)
		return (node_env);
	replace = replace_env_var(envs, node_env->name, node_env->content);
	if (replace)
	{
		free(node_env->name);
		free(node_env->content);
		free(node_env);
		return (envs);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node_env;
	return (envs);
}

t_env	*add_node_env(t_env *envs, char *av)
{
	t_env	*node_env;

	node_env = create_node_env(av);
	if (!node_env)
		return (envs);
	return (add_env_back(envs, node_env));
}
