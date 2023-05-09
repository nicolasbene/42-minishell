/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:56 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/09 14:19:03 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	ft_isspace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

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
	if ((j > 19 && sign == 1) || (j > 20 && sign == -1)) // ici
		*toolongnb = 1;
	return (sum * sign);
}

void	ft_error_numeric(char *arg, t_cmd *cmd)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_minishell.exit_status = 2;
	ft_exit(cmd, 1);
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
			&& arg[i] != '\v' && arg[i] != ' ') // ici
		{
			if (arg[i] < 48 || arg[i] > 57)
				ft_error_numeric(arg, cmd);
		}
		i++;
	}
}

void	ft_exit(t_cmd *cmd, int i)
{
	free_commands(cmd);
	if (g_minishell.envs)
		free_envs(&g_minishell.envs);
	if (i == 1)
		ft_putstr_fd("exit\n", 2);
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
		ft_exit(cmd, 1); // ici
	}
}
