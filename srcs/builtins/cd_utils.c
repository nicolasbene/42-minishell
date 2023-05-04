/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:51:11 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/04 18:37:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

char	*ft_getenv(char *str)
{
	t_env	*tmp;

	tmp = g_minishell.envs;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (ft_strdup(tmp->content));
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_add_env(char *env_name, char *new_content)
{
	t_env	*node_env;

	node_env = malloc(sizeof(*node_env));
	if (!node_env)
		return (NULL);
	node_env->name = ft_strdup(env_name);
	if (node_env->name == NULL)
		return (free(node_env), NULL);
	node_env->content = ft_strdup(new_content);
	if (node_env->content == NULL)
		return (free(node_env->name), free(node_env), NULL);
	node_env->next = NULL;
	add_env_back(g_minishell.envs, node_env);
	return (node_env); // ici
}

int	ft_setenv(char *env_name, char *new_content)
{
	int		i;
	size_t	len;

	if (!env_name || !new_content)
		return (0);
	len = ft_strlen(env_name);
	i = ft_intoenv(env_name);
	if (i != -1)
		return (ft_switchenvcont(new_content, i));
	else
	{
		ft_add_env(env_name, new_content);
		return (1);
	}
	return (0);
}

int	ft_switchenvcont(char *new_content, int index)
{
	t_env	*tmp;
	int		i;
	char	*new;

	i = -1;
	tmp = g_minishell.envs;
	while (++i < index)
		tmp = tmp->next;
	new = ft_strdup(new_content);
	if (!new)
		return (0);
	free(tmp->content);
	tmp->content = new;
	return (1);
}
