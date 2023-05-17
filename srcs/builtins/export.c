/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:56 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 18:32:04 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

static char	*print_name(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	av[i] = '\0';
	print_error("export: `%s': not a valid identifier", av, NULL);
	return (av);
}

static int	check_char(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '=')
			break ;
		if (av[i] < '0')
			return (0);
		else if (av[i] > '9' && av[i] < '=')
			return (0);
		else if (av[i] > '=' && av[i] < 'A')
			return (0);
		else if (av[i] > 'Z' && av[i] < '_')
			return (0);
		else if (av[i] > '_' && av[i] < 'a')
			return (0);
		else if (av[i] > 'z')
			return (0);
		else
			i++;
	}
	return (1);
}

int	valid_name(char *av)
{
	int	i;

	if (av[0] == '=')
		return (print_name(av), 1);
	i = 0;
	while (av[i])
	{
		if ((av[0] > '0' && av[0] < '9') || !check_char(av))
		{
			print_error("%s: `%s': not a valid identifier", "export", av);
			return (1);
		}
		i++;
	}
	if (ft_strchr(av, '=') == NULL)
		return (1);
	return (0);
}

int	print_envs(t_env *envs)
{
	t_env	*env;

	while (envs)
	{
		env = envs;
		printf("export %s", env->name);
		if (env->content)
			printf("=\"%s\"\n", env->content);
		else
			printf("\n");
		envs = envs->next;
	}
	return (0);
}

int	ft_export(int ac, char **av)
{
	int		i;
	int		ret;
	int		valid;
	t_env	*envs;

	envs = g_minishell.envs;
	ret = 0;
	if (ac == 1)
		return (print_envs(envs));
	i = 1;
	while (av[i])
	{
		valid = valid_name(av[i]);
		if (valid == 0)
			g_minishell.envs = add_node_env(envs, av[i]);
		else
			ret = 1;
		i++;
	}
	g_minishell.exit_status = ret;
	return (ret);
}
