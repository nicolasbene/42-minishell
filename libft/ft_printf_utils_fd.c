/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:09:14 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/17 14:41:26 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pfputnbr_fd(long int c, int fd)
{
	int	len;

	len = 0;
	if (c < 0)
	{
		len += ft_pfputchar_fd('-', fd);
		c = -c;
	}
	if (c >= 0 && c <= 9)
		len += ft_pfputchar_fd(c + 48, fd);
	if (c >= 10)
	{
		len += ft_pfputnbr_fd(c / 10, fd);
		len += ft_pfputchar_fd(c % 10 + 48, fd);
	}
	return (len);
}

int	ft_putnbr_u_fd(unsigned int c, int fd)
{
	int	len;

	len = 0;
	if (c <= 9)
		len += ft_pfputchar_fd(c + 48, fd);
	if (c >= 10)
	{
		len += ft_putnbr_u_fd(c / 10, fd);
		len += ft_pfputchar_fd(c % 10 + 48, fd);
	}
	return (len);
}

int	ft_putnbr_x_fd(unsigned long c, int fd)
{
	int	len;

	len = 0;
	if (c <= 15)
		len += ft_pfputchar_fd(BASEX[c], fd);
	if (c >= 16)
	{
		len += ft_putnbr_x_fd(c / 16, fd);
		len += ft_pfputchar_fd(BASEX[c % 16], fd);
	}
	return (len);
}

int	ft_putnbr_xc_fd(unsigned int c, int fd)
{
	int	len;

	len = 0;
	if (c <= 15)
		len += ft_pfputchar_fd(BASEXC[c], fd);
	if (c >= 16)
	{
		len += ft_putnbr_xc_fd(c / 16, fd);
		len += ft_pfputchar_fd(BASEXC[c % 16], fd);
	}
	return (len);
}

int	ft_putnbr_p_fd(unsigned long c, int fd)
{
	int				len;

	len = 0;
	if (c == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	len += ft_pfputstr_fd("0x", fd);
	len += ft_putnbr_x_fd(c, fd);
	return (len);
}
