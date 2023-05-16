/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:36:35 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/15 19:49:51 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

static void	sighandler_heredoc(int signum)
{
	(void)signum;
	printf("\n");
	g_minishell.exit_status = 130;
}

void	handle_signals_heredoc(void)
{
	signal(SIGINT, &sighandler_heredoc);
}

static void	sighandler(int signum)
{
	(void)signum;
	if (isatty(STDOUT_FILENO))
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_minishell.exit_status = 1;
}

void	handle_signals(void)
{
	signal(SIGINT, &sighandler);
	signal(SIGQUIT, SIG_IGN);
	g_minishell.signal = 0;
}
