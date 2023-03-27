/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:17:37 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/09 21:24:11 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	pos;
	char	*str;

	pos = 0;
	str = (char *)s;
	while (pos < n)
	{
		if (((unsigned char *)str)[pos] == (unsigned char)c)
			return ((char *)s + pos);
		pos++;
	}
	return (NULL);
}
