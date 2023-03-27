/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:27:18 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/07 17:13:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_iteration(char *new, int i, long int l_n)
{
	while (l_n > 0)
	{
		new[i] = (l_n % 10) + 48;
		l_n = l_n / 10;
		i--;
	}
	return (new);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*new;
	long int	l_n;

	l_n = n;
	i = ft_len(l_n);
	new = (char *)malloc((i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i--;
	if (l_n == 0)
	{
		new[0] = 48;
		return (new);
	}
	if (l_n < 0)
	{
		new[0] = '-';
		l_n = -l_n;
	}
	if (l_n > 0)
		ft_iteration(new, i, l_n);
	return (new);
}
