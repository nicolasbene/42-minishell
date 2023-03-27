/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:23:49 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/07 16:01:11 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			tmp = (char *)&s[i];
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	else if (tmp != NULL)
		return (tmp);
	else
		return (0);
}
