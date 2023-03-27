/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:44:55 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/13 11:51:31 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_g(char *buff, char *buff2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc((ft_strlen_g(buff) + ft_strlen_g(buff2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		new[i] = buff[i];
		i++;
	}
	j = 0;
	while (buff2[j])
	{
		new[i + j] = buff2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

int	ft_strchr_g(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_getres(char *res, char *buff)
{
	if (!(buff))
	{
		buff = malloc(1);
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	buff = ft_strjfree(buff, res);
	return (buff);
}

int	has_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
