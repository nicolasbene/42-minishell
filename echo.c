/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/31 11:31:03 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define false	0
#define true	1

int	echo_newline(char **av, int i)
{
	int j;

	if (av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != 'n')
				return (false);
			j++;
		}
		return (true);
	}
	return (false);
}

int	echo(int ac, char **av)
{
	int	i;
	int newline_option;
	
	i = 2;
	newline_option = false;
	while (av[i])
	{
		newline_option = echo_newline(av, i);
		if (!newline_option)
			break ;
		i++;
	}
	if (i != 1)
		newline_option = true;
	while (i < ac)
	{
		printf("%s", av[i]);
		i++;
		if (i != ac)
			printf(" ");
	}
	if (!newline_option)
		printf("\n");
	return (0);
}

// int main(int ac, char **av)
// {
// 	echo(ac, av);
// }