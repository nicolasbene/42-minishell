/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:18:47 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/16 16:01:44 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pfputchar_fd(int c, int fd)
{
	int	len;

	len = write(fd, &c, 1);
	return (len);
}

int	ft_pfputstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_checkarg_fd(int c, va_list ap, int fd)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_pfputchar_fd(va_arg(ap, int), fd);
	if (c == 's')
		len = ft_pfputstr_fd(va_arg(ap, char *), fd);
	if (c == 'p')
		len = ft_putnbr_p_fd(va_arg(ap, unsigned long), fd);
	if (c == 'd' || c == 'i')
		len = ft_pfputnbr_fd((long int)va_arg(ap, int), fd);
	if (c == 'u')
		len = ft_putnbr_u_fd(va_arg(ap, unsigned int), fd);
	if (c == 'x')
		len = ft_putnbr_x_fd(va_arg(ap, unsigned int), fd);
	if (c == 'X')
		len = ft_putnbr_xc_fd(va_arg(ap, unsigned int), fd);
	if (c == '%')
		len = ft_pfputchar_fd('%', fd);
	return (len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	size_t	i;
	va_list	ap;
	int		len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			len += ft_checkarg_fd(str[i], ap, fd);
		}
		else
		{
			len += ft_pfputchar_fd(str[i], fd);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
