/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/18 19:46:25 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	print_env(t_env *envs)
{
	int	i;

	i = 0;
	while (envs != NULL)
	{
		if (envs->content)
			i = printf("%s=%s\n", envs->name, envs->content);
		envs = envs->next;
	}
	return (i);
}

int	ft_env(int ac, char **av)
{
	t_env	*envs;
	int		i;

	envs = g_minishell.envs;
	if (ac == 1)
	{
		i = print_env(envs);
		if (i == -1)
			print_error("%s: write error", "env", NULL);
		return (g_minishell.exit_status = 0);
	}
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "env") == 0)
		{
			print_env(envs);
			return (g_minishell.exit_status = 0);
		}
		print_error("%s: `%s': No such file or directory", "env", av[1]);
		return (g_minishell.exit_status = 127);
	}
	return (g_minishell.exit_status = 0);
}
