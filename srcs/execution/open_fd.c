/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:37:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/26 15:22:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	get_open_flag(t_rdtype type)
{
	if (type == RD_INF)
		return (O_RDONLY);
	if (type == RD_OUT)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (type == RD_APP)
		return (O_WRONLY | O_CREAT | O_APPEND);
	return (O_RDWR);
}

int	handle_open_error(const char *s, int type)
{
	(void)s;
	(void)type;
	return (0);
}

int	open_fd(t_rdtype type, char *file)
{
	int		fd;

	if (type == RD_HERE)
	{
		fd = -2;
		print_error("%s: HEREDOC EN COURS DE BUILD", file, NULL);
	}
	else
	{
		fd = -2;
		if (handle_open_error(file, type) == 0)
			fd = open(file, get_open_flag(type), 0644);
		if (fd == -1)
		{
			print_error("%s: No such file or directory", file, NULL);
			fd = -2;
		}
		if (fd == -2)
			g_minishell.exit_status = 1;
	}
	return (fd);
}
