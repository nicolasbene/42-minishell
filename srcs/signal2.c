/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:36:59 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/18 19:40:09 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	reset_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	sighandler_exec(int signum)
{
	(void)signum;
	printf("\n");
}

void	handle_signals_exec(void)
{
	signal(SIGINT, &sighandler_exec);
}

static void	sighandler_heredoc_child(int signum)
{
	(void)signum;
	free_envs(g_minishell.envs);
	free_commands(g_minishell.commands);
	close_save_std();
	printf("\n");
	g_minishell.exit_status = 130;
	exit(0);
}

void	handle_signals_heredoc_child(void)
{
	signal(SIGINT, &sighandler_heredoc_child);
	signal(SIGQUIT, SIG_IGN);
}
