/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 16:23:36 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

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

t_env	*add_env_back(t_env *env, t_env *node_env)
{
	t_env	*tmp;

	tmp = env;
	if (!env)
		return (node_env);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node_env;
	return (env);
}

t_env	*add_node_env(t_env *envs, char *av)
{
	t_env	*node_env;

	node_env = create_node_env(av);
	if (!node_env)
		return (envs);
	return (add_env_back(envs, node_env));
}

t_env	*tab_to_list(char **envp)
{
	t_env	*envs;
	int		i;

	i = 0;
	envs = NULL;
	while (envp[i])
	{
		envs = add_node_env(envs, envp[i]);
		i++;
	}
	return (envs);
}

int	ft_env(int ac, char **av)
{
	t_env	*envs;
	int		i;

	i = 0;
	(void)av;
	envs = g_minishell.envs;
	if (ac == 1)
	{
		while (envs != NULL)
		{
			if (envs->content)
				i = printf("%s=%s\n", envs->name, envs->content);
			envs = envs->next;
		}
		if (i == -1)
			print_error("%s: write error", "env", NULL);
		return (g_minishell.exit_status = 0);
	}
	return (g_minishell.exit_status = 0);
}
