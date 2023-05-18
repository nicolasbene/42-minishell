/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:56 by nwyseur           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/18 11:57:45 by nibenoit         ###   ########.fr       */
=======
/*   Updated: 2023/05/17 22:12:41 by nibenoit         ###   ########.fr       */
>>>>>>> ef43cc1c00c511a396cc1feddc85ff9ffbb9a57f
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

long long	ft_atoi_exit(const char *str, int i, int *toolongnb)
{
	int			j;
	long		sign;
	long long	sum;

	sign = 1;
	sum = 0;
	j = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && (ft_isspace(str[i]) || str[i] == '0'))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && ++j)
	{
		sum = (sum * 10) + (str[i] - 48);
		if (((i == 18 && sign == 1) && (str[i] > '7' && str[i] <= '9'))
			|| ((i == 19 && sign == -1) && (str[i] == '9')))
			*toolongnb = 1;
		i++;
	}
	while (str[i++])
		j++;
	if ((j > 19 && sign == 1) || (j > 20 && sign == -1))
		*toolongnb = 1;
	return (sum * sign);
}

void	ft_parsing_exitarg(char *arg, t_cmd *cmd)
{
	int		i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] != '\f' && arg[i] != '\t' && arg[i] != '\r'
			&& arg[i] != '\v' && arg[i] != ' ')
		{
			if (arg[i] < 48 || arg[i] > 57)
				ft_error_numeric(arg, cmd);
		}
		i++;
	}
}

void	ft_exit(t_cmd *cmd, int i)
{
	if (g_minishell.envs)
		free_envs(g_minishell.envs);
	if (i == 1)
		ft_putstr_fd("exit\n", 2);
<<<<<<< HEAD
	free_commands(cmd);
=======
	if (cmd)
		free_commands(cmd);
>>>>>>> ef43cc1c00c511a396cc1feddc85ff9ffbb9a57f
	close_save_std();
	exit(g_minishell.exit_status);
}

void	ft_init_exit(char **args, t_cmd *cmd, int i)
{
	int			toolongnb;
	long long	coderr;

	toolongnb = 0;
	g_minishell.exit_status = 0;
	if (!args[1])
		ft_exit(cmd, 1);
	ft_parsing_exitarg(args[1], cmd);
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_minishell.exit_status = 1;
	}
	else
	{
		coderr = ft_atoi_exit(args[1], 0, &toolongnb);
		if (toolongnb == 1)
			ft_error_numeric(args[1], cmd);
		g_minishell.exit_status = coderr % 256;
		ft_exit(cmd, 1);
	}
}
