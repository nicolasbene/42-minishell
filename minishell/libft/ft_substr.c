/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:17 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/15 20:03:05 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;
	size_t	size;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s))
		size = len + 1;
	else
		size = ft_strlen(s) - start + 1;
	new = ft_calloc(size, sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
