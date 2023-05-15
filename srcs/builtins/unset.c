/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:51:47 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/15 14:56:01 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	unset_var(int index)
{
	t_env	*tmp;
	t_env	*prev;
	int		i;

	i = 0;
	tmp = g_minishell.envs;
	if (index == 0)
	{
		g_minishell.envs = g_minishell.envs->next;
		free_envs(tmp);
		return ;
	}
	while (i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	prev->next = tmp->next;
	free_envs(tmp);
	return ;
}

int	ft_intoenv(char *tofind)
{
	int		i;
	int		str;
	t_env	*tmp;

	i = 0;
	str = 0;
	tmp = g_minishell.envs;
	while (tmp != NULL)
	{
		str = ms_strcmp(tmp->name, tofind);
		if (str == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_unset(char **args)
{
	int	i;
	int	index;

	g_minishell.exit_status = 0;
	if (!args[1])
		return (1);
	i = 0;
	while (args[++i])
	{
		index = ft_intoenv(args[i]);
		if (index != -1)
			unset_var(index);
		else
		{
			ft_putstr_fd("Unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not an existing variable\n", 2);
			g_minishell.exit_status = 1;
		}
	}
	return (1);
}
