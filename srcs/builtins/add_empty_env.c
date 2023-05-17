/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_empty_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:11:41 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 15:42:40 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	check_equal(char **av)
{
	char	*value;

	value = ft_strchr(av[1], '=');
	if (!value)
		return (0);
	return (1);
}

t_env	*add_empty_env(t_env *envs, char *s)
{
	t_env	*env;
	t_env	*new;

	env = malloc(sizeof(*env));
	if (!env)
		exit(12);
	env->name = ft_strdup(s);
	if (!env->name)
		exit(12);
	env->content = NULL;
	env->next = NULL;
	new = env;
	if (!new)
		exit(12);
	if (!envs)
		return (new);
	while (envs->next)
		envs = envs->next;
	envs->next = new;
	return (envs);
}
