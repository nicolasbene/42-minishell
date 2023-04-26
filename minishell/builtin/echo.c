/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:55:05 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/26 11:10:50 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ncheck(char *str)
{
	
}

int	ft_nbargs(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_echo(char **args)
{
	int	i;
	int	is_n;

	i = 1;
	is_n = 0;
	if (ft_nbargs(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			is_n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (is_n == 0)
		write(1, "\n", 1);
	return (1);
}