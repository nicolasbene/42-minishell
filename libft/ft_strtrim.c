/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:53:16 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/10 17:28:24 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isin(char a, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ret;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && isin(s1[start], set))
		start++;
	start--;
	while (s1[end] && isin(s1[end], set) && end > start)
		end--;
	end++;
	ret = malloc(end - start);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start + 1, end - start);
	return (ret);
}
