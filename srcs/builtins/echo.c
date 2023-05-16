/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/16 15:19:31 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

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

int	ft_echo(int ac, char **av, int i)
{
	int	newline_option;

	newline_option = FALSE;
	while (av[++i])
	{
		newline_option = echo_newline(av, i);
		if (!newline_option)
			break ;
	}
	if (i != 1)
		newline_option = TRUE;
	while (i < ac)
	{
		printf("%s", av[i++]);
		if (i != ac)
			printf(" ");
	}
	if (!newline_option)
		i = printf("\n");
	if (i == -1)
	{
		print_error("%s: write error", "echo", NULL);
		return (g_minishell.exit_status = 1);
	}
	return (g_minishell.exit_status = 0);
}
