/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:43:20 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/26 15:22:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

char	*ft_strjoinchara(char *s1, char c)
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

int	ft_ischara(char c)
{
	if (!(c >= 9 && c <= 13) && c != 32 && c != '|'
		&& c != '>' && c != '<' && c != '\0')
		return (1);
	return (0);
}

int	ft_strchrms(char *str, int c)
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
