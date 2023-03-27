/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:22 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/15 19:59:10 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_trimlen(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (ft_set(str[j], set) == 1 && str[j])
		j++;
	k = i - 1;
	while (ft_set(str[k], set) == 1 && k > 0)
	{
		k--;
		j++;
	}
	if (j > i)
		return (0);
	return (i - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	len = ft_trimlen(s1, set);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	while (ft_set(s1[i], set) == 1 && s1[i])
		i++;
	while (j < len)
	{
		new[j] = s1[i + j];
		j++;
	}
	return (new);
}
