/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:31:53 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/08 15:51:40 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)pointer;
	i = 0;
	while (i < count)
	{
		ptr[i] = (char)value;
		i++;
	}
	return (pointer);
}
