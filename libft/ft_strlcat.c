/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:26 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/08 20:16:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	lendst;

	if (size == 0 || size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	a = 0;
	lendst = ft_strlen(dest);
	while (src[a] && (a + lendst) < (size - 1))
	{
		dest[a + lendst] = src[a];
		a++;
	}
	dest[a + lendst] = '\0';
	return (lendst + ft_strlen(src));
}
