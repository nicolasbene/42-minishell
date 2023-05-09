/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:00:40 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/09 12:39:41 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_pwd(void)
{
	char	buff[PATH_MAX];
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(buff, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, 1);
		return (EXIT_SUCCESS);
	}
	print_error("pwd", strerror(errno), NULL);
	return (EXIT_FAILURE);
}
