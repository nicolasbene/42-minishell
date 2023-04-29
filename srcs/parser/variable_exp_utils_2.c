/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:48 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/29 15:15:08 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_lookfor(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (1);
	else
		return (0);
}

void	ms_swap(char **str, char *new)
{
	char	*tmp;

	tmp = (*str);
	(*str) = new;
	free(tmp);
}

char	ms_isep(char *s)
{
	int	i;

	i = 0;
	while (ft_isalnum(s[i]) == 1 || s[i] == '_')
		i++;
	return (s[i]);
}

int	ms_strlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

void	ft_istreat(char **str, t_chir *chir)
{
	int	l;

	l = chir->posdollar;
	while ((*str)[l] && (*str)[l] != '$')
		l++;
	if ((*str)[l] == '$' && (*str)[l + 1] == '\"')
		chir->totreat = 0;
	else
		chir->totreat = 1;
}
