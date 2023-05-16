/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:00:40 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/16 15:21:17 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

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
		{
			print_error("%s: write error", "pwd", NULL);
			return (g_minishell.exit_status = 1);
		}
		return (g_minishell.exit_status = 0);
	}
	print_error("pwd", strerror(errno), NULL);
	return (g_minishell.exit_status = 1);
}
