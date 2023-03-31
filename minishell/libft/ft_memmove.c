/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:41:42 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/08 18:15:22 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*desti;
	char	*source;

	desti = (char *)dest;
	source = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		while (size-- > 0)
			desti[size] = source[size];
		return (dest);
	}
	while (i < size)
	{
		desti[i] = source[i];
		i++;
	}
	return (dest);
}
