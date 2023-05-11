/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:31:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/11 09:14:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

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

int	executing(t_cmd *commands)
{
	int	tpin;
	int	tpout;
	int	last_pid;

	save_std(&tpin, &tpout);
	last_pid = pipex(commands);
	restore_std(tpin, tpout);
	if (last_pid == -1)
		return (-1);
	while (wait(NULL) != -1)
		;
	
	//on gerera surement les signaux juste apres
	
	return (0);
}
