/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:22:56 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/12 15:18:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		result = malloc(sizeof(*result) * 1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	result = malloc(sizeof(*result) * (size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s[start], size + 1);
	return (result);
}
