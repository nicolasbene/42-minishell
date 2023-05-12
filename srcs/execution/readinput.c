/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:25:52 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/11 14:58:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

char	*readinput(const char *prompt)
{
	size_t	last;
	char	*line;

	line = NULL;
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		line = readline(prompt);
	else
	{
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			last = ft_strlen(line);
			if (last != 0 && line[last - 1] == '\n')
				line[last] = 0;
		}
	}
	return (line);
}
