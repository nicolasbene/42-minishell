/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:05:39 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/01 17:22:17 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_intosmpl(char **str, int pos)
{
	int	l;
	int	j;
	int	k;

	l = -1;
	j = 0;
	k = 0;
	while ((*str)[++l] && l <= pos)
	{
		if ((*str)[l] == '\'')
			j++;
	}
	while ((*str)[l])
	{
		if ((*str)[l] == '\'')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}

int	ft_intodbl(char **str, int pos)
{
	int	l;
	int	j;
	int	k;

	l = -1;
	j = 0;
	k = 0;
	while ((*str)[++l] && l <= pos)
	{
		if ((*str)[l] == '\"')
			j++;
	}
	while ((*str)[l])
	{
		if ((*str)[l] == '\"')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}

char	*ft_strjoinnbr(char *s1, char c)
{
	int		l_string;
	int		i;
	char	*new;

	i = 0;
	l_string = ft_strlen(s1) + 2;
	new = (char *)malloc(l_string * sizeof(char));
	if (!new)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	i++;
	new [i] = '\0';
	free(s1);
	return (new);
}
