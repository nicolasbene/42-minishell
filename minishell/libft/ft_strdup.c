/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:22:15 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/15 21:12:06 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	new = (char *) malloc((len + 1) * sizeof(char));
	if (new != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
