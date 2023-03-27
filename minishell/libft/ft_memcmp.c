/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:17:44 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/15 20:03:11 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str[i] != str2[i])
			return ((unsigned char)str[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
