/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:27 by nwyseur           #+#    #+#             */
/*   Updated: 2022/11/07 15:22:55 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	rslt;
	int	sign;

	i = 0;
	rslt = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == 45)
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		rslt = rslt * 10;
		rslt = rslt + str[i] - 48;
		i++;
	}
	return (rslt * sign);
}
