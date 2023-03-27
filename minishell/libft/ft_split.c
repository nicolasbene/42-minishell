/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:54:31 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/20 11:37:37 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlen(char const*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	j;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			j = 0;
			wc = wc + 1;
			while (s[i + j] != '\0' && s[i + j] != c)
				j++;
			i = i + j;
		}
	}
	return (wc);
}

void	ft_strfree(char **sstr, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
}

char	*ft_copyword(char const *s, int len, char **sstr, int j)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
	{
		ft_strfree(sstr, j);
		return (NULL);
	}
	while (s[i] != '\0' && i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			new[j] = ft_copyword(&s[i], ft_wordlen(&s[i], c), new, j);
			if (new[j] == NULL)
				return (NULL);
			j++;
			i = i + ft_wordlen(&s[i], c);
		}
	}
	new[j] = 0;
	return (new);
}
