/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:26:42 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/14 16:26:03 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wrdcnt(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*cpywrd(char const *s, char c)
{
	char	*wrd;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	wrd = malloc(sizeof(char) * (len + 1));
	if (!wrd)
	{
		free(wrd);
		return (NULL);
	}
	ft_memcpy(wrd, s, len);
	wrd[len] = '\0';
	return (wrd);
}

void	*free_and_return(char **tab)
{
	int	i;

	if (!(tab))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	a;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (wrdcnt(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			ret[a] = cpywrd(s + i, c);
			if (!ret[a++])
				return (free_and_return(ret));
			while (s[i + 1] && s[i + 1] != c)
				i++;
		}
		i++;
	}
	ret[a] = 0;
	return (ret);
}
