/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:23:43 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/09 21:11:31 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(nee) == 0)
		return ((char *)hay);
	while (i < len && hay[i])
	{
		j = 0;
		while (i + j < len && hay[i + j] == nee[j] && nee[j])
			j++;
		if (nee[j] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
