/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:44:39 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/13 11:52:34 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjfree(char *buff, char *buff2)
{
	char	*new;

	new = ft_strjoin_g(buff, buff2);
	free(buff);
	return (new);
}

char	*ft_nextline(char *buff, char *res)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i])
	{
		res[j] = buff[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(buff);
	if (res[0] == '\0')
		return (NULL);
	return (res);
}

char	*ft_getline(char *buff)
{
	char	*new;
	size_t	ltrlen;
	size_t	i;

	ltrlen = 0;
	while (buff[ltrlen] && buff[ltrlen] != '\n')
		ltrlen++;
	if (buff[ltrlen] == '\n')
		ltrlen++;
	new = malloc((ltrlen + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		new[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_read_file(int fd, char *buff)
{
	char	*buff2;
	int		ret;

	ret = BUFFER_SIZE;
	while (ret > 0)
	{
		buff2 = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff2)
			return (NULL);
		ret = read(fd, buff2, BUFFER_SIZE);
		if ((ret == 0 && ft_strlen_g(buff) == 0) || ret == -1)
			return (free(buff), free(buff2), NULL);
		buff2[ret] = '\0';
		buff = ft_strjfree(buff, buff2);
		free(buff2);
		if (ft_strchr_g(buff, '\n') == 1)
			break ;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*ltr;
	char		*buff;
	static char	res[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = NULL;
	buff = ft_getres(res, buff);
	if (!has_newline(buff))
		buff = ft_read_file(fd, buff);
	if (buff == NULL)
		return (NULL);
	ltr = ft_getline(buff);
	if (ltr[0] == '\0')
	{
		free(ltr);
		free(buff);
		return (NULL);
	}
	ft_nextline(buff, res);
	return (ltr);
}
