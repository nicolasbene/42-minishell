/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/04 15:20:26 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	free_env(t_env *env)
{
	if (env)
	{
		free(env->name);
		free(env->content);
		free(env);
	}
}

void	free_envs(t_env **envs)
{
	t_env	*tmp;

	if (!envs || !*envs)
		return ;
	while (*envs)
	{
		tmp = *envs;
		*envs = (*envs)->next;
		free_env(tmp);
	}
}

t_env *create_node_env(char *av)
{
    t_env *node_env;
    int i;

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

t_env *add_env_back(t_env *env, t_env *node_env)
{
    if (!env)
        return (node_env);
    t_env *tmp = env;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node_env;
    return (env);
}

t_env *add_node_env(t_env *envs, char *av)
{
    t_env *node_env = create_node_env(av);
    if (!node_env)
        return (envs);
    return (add_env_back(envs, node_env));
}

t_env *tab_to_list(char **envp)
{
    t_env *envs = NULL;
    int i = 0;
    while (envp[i])
    {
        envs = add_node_env(envs, envp[i]);
        i++;
    }
    return (envs);
}
