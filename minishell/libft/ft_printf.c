/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:18:47 by nwyseur           #+#    #+#             */
/*   Updated: 2023/01/05 14:28:02 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_checkarg(int c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(ap, int));
	if (c == 's')
		len = ft_putstr(va_arg(ap, char *));
	if (c == 'p')
		len = ft_putnbr_p(va_arg(ap, unsigned long));
	if (c == 'd' || c == 'i')
		len = ft_putnbr((long int)va_arg(ap, int));
	if (c == 'u')
		len = ft_putnbr_u(va_arg(ap, unsigned int));
	if (c == 'x')
		len = ft_putnbr_x(va_arg(ap, unsigned int));
	if (c == 'X')
		len = ft_putnbr_xc(va_arg(ap, unsigned int));
	if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
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
			len += ft_checkarg(str[i], ap);
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
