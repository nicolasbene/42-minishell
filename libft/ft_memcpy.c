/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:32 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/12 17:18:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*desti;
	char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	desti = (char *)dest;
	source = (char *)src;
	i = 0;
	while (i < size)
	{
		desti[i] = source[i];
		i++;
	}
	return (dest);
}
