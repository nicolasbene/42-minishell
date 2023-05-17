/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:43:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 15:01:45 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	print_error(const char *format, const char *arg1, const char *arg2)
{
	ft_printf_fd(2, "minishell: ");
	if (arg2)
		ft_printf_fd(2, format, arg1, arg2);
	else if (arg1)
		ft_printf_fd(2, format, arg1);
	else
		ft_printf_fd(2, "%s", format);
	ft_printf_fd(2, "\n");
}
