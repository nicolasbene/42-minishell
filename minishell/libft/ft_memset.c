/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:19:12 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/08 20:58:59 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		((unsigned char *)ptr)[pos] = (unsigned char)x;
		pos ++;
	}
	return (ptr);
}
