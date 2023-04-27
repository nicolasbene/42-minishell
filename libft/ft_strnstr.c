/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:42:07 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/09 18:16:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	if (!str && len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		a = 0;
		while (str[i + a] == to_find[a] && (i + a) < len)
		{
			if (to_find[a + 1] == '\0')
				return ((char *)(str + i));
			a++;
		}
		i++;
	}
	return (NULL);
}
