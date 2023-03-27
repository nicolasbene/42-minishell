/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:17:54 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/09 18:58:39 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	pos;

	pos = 0;
	if (!dst && !src)
		return (NULL);
	while (pos < n)
	{
		((char *)dst)[pos] = ((const char *)src)[pos];
		pos++;
	}
	return (dst);
}
