/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:22:37 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/07 15:54:59 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_string;
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	l_string = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(l_string * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new [i + j] = '\0';
	return (new);
}
