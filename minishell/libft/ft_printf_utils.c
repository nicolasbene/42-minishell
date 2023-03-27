/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:09:14 by nwyseur           #+#    #+#             */
/*   Updated: 2023/01/05 14:28:14 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long int c)
{
	int	len;

	len = 0;
	if (c < 0)
	{
		len += ft_putchar('-');
		c = -c;
	}
	if (c >= 0 && c <= 9)
		len += ft_putchar(c + 48);
	if (c >= 10)
	{
		len += ft_putnbr(c / 10);
		len += ft_putchar(c % 10 + 48);
	}
	return (len);
}

int	ft_putnbr_u(unsigned int c)
{
	int	len;

	len = 0;
	if (c <= 9)
		len += ft_putchar(c + 48);
	if (c >= 10)
	{
		len += ft_putnbr_u(c / 10);
		len += ft_putchar(c % 10 + 48);
	}
	return (len);
}

int	ft_putnbr_x(unsigned long c)
{
	int	len;

	len = 0;
	if (c <= 15)
		len += ft_putchar(BASEX[c]);
	if (c >= 16)
	{
		len += ft_putnbr_x(c / 16);
		len += ft_putchar(BASEX[c % 16]);
	}
	return (len);
}

int	ft_putnbr_xc(unsigned int c)
{
	int	len;

	len = 0;
	if (c <= 15)
		len += ft_putchar(BASEXC[c]);
	if (c >= 16)
	{
		len += ft_putnbr_xc(c / 16);
		len += ft_putchar(BASEXC[c % 16]);
	}
	return (len);
}

int	ft_putnbr_p(unsigned long c)
{
	int				len;

	len = 0;
	if (c == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += ft_putstr("0x");
	len += ft_putnbr_x(c);
	return (len);
}
