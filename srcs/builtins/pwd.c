/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:00:40 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/15 19:15:50 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_pwd(void)
{
	char	buff[PATH_MAX];
	char	*cwd;
	int		i;


	i = 0;
	cwd = NULL;
	cwd = getcwd(buff, PATH_MAX);
	if (cwd)
	{
		i = ft_putendl_fd(cwd, 1);
		if (i == -1)
			print_error("%s: write error", "pwd", NULL);
		return (EXIT_SUCCESS);
	}
	print_error("pwd", strerror(errno), NULL);
	return (EXIT_FAILURE);
}
