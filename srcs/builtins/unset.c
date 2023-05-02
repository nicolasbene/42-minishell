/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:51:47 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/02 18:39:28 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	unset_var(t_env *env, int index)
{
	t_env	*tmp;
	t_env	*todel;
	int		i;

	i = 0;
	tmp = env;
	while (i < index)
	{
		tmp = tmp->next;
		i++;
	} // finir la chirurgie
		tmp = ft_strdup(g_envs[i + 1]);
		free(g_envs[i]);
		g_envs[i] = tmp;
		i++;
	return (1);
}

int	ft_intoenv(t_env *env, char *tofind)
{
	int		i;
	int		str;

	i = 0;
	str = 0;
	while (env != NULL)
	{
		str = ms_strcmp(env->name, tofind);
		if (str == 0)
			return (i);
		i++;
		env = env->next;
	}
	return (-1);
}

int	ft_unset(char **args, t_env **env)
{
	int	i;
	int	index;

	if (!args[1])
		return (1);
	i = 0;
	while (args[++i])
	{
		index = ft_intoenv(*env, args[i]);
		if (index != -1)
			unset_var(*env, index);
		else
		{
			ft_putstr_fd("Unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not an existing variable\n", 2);
		}
	}
	return (1);
}