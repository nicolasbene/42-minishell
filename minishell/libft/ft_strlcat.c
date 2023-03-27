/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:22:43 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/08 20:22:44 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	if (size == 0 || size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = 0;
	len_dst = ft_strlen(dest);
	while (src[i] && (i + len_dst) < (size - 1))
	{
		dest[i + len_dst] = src[i];
		i++;
	}
	dest[i + len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}
