/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_split_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:07:16 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/14 15:08:18 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

int	ms_passquote(char *arg, char c)
{
	int	i;

	i = 0;
	i++;
	while (arg[i] != c)
		i++;
	return (i + 1);
}

int	ms_wordcount_i(char *arg, int *wc)
{
	int	k;

	k = 0;
	++(*wc);
	while (arg[k] != '\0' && arg[k] != ' ')
	{
		if (arg[k] == '\"' || arg[k] == '\'')
			k += ms_passquote(&arg[k], arg[k]);
		else
			k++;
	}
	return (k);
}

void	ms_wordcount(char **arg, int *wc)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i] != NULL)
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			if (arg[i][j] == ' ')
				j++;
			if (arg[i][j] != '\0' && arg[i][j] != ' ')
				j += ms_wordcount_i(&arg[i][j], wc);
		}
	}
}

int	ft_wordlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != ' ')
	{
		if (s[i] == '\"' || s[i] == '\'')
			i += ms_passquote(&s[i], s[i]);
		else
			i++;
	}
	return (i);
}
