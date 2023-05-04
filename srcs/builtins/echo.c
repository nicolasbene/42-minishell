/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/04 18:00:04 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

# define FALSE	0
# define TRUE	1

int	echo_newline(char **av, int i)
{
	int j;

	if (av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] != 'n')
				return (FALSE);
			j++;
		}
		return (TRUE);
	}
	return (FALSE);
}

int	echo(int ac, char **av)
{
	int	i;
	int newline_option;
	
	i = 1;
	newline_option = FALSE;
	while (av[i])
	{
		newline_option = echo_newline(av, i);
		if (!newline_option)
			break ;
		i++;
	}
	if (i != 1)
		newline_option = TRUE;
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
