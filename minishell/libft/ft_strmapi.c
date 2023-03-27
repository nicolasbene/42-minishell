/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:20:46 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/08 22:36:18 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*new;

	i = 0;
	new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[ft_strlen(s)] = '\0';
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
