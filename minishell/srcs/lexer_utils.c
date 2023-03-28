/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:43:20 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/28 15:05:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_lexer.h"

char	*ft_strjoinchara(char *s1, char c)
{
	int		l_string;
	int		i;
	char	*new;

	i = 0;
	l_string = ft_strlen(s1) + 2;
	new = (char *)malloc(l_string * sizeof(char));
	if (new == NULL)
		return (NULL);
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
