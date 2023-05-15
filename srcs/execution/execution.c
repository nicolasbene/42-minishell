/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:31:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/15 10:33:38 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	save_std(int *tpin, int *tpout)
{
	*tpin = dup(STDIN_FILENO);
	*tpout = dup(STDOUT_FILENO);
}

void	restore_std(int tpin, int tpout)
{
	dup2(tpin, STDIN_FILENO);
	dup2(tpout, STDOUT_FILENO);
	close(tpin);
	close(tpout);
}

int	executing(t_cmd *cmd)
{
	int	tpin;
	int	tpout;
	int	last_pid;
	int	status;

	save_std(&tpin, &tpout);
	last_pid = pipex(cmd);
	restore_std(tpin, tpout);
	if (last_pid == -1)
		return (-1);
	if (last_pid > 0)
	{
		waitpid(last_pid, &status, 0);
		if (WIFEXITED(status))
			g_minishell.exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_minishell.exit_status = WTERMSIG(status) + 128;
	}
	while (wait(&status) != -1)
		continue ;
	return (0);
}
