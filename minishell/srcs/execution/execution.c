/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:31:09 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/21 10:10:36 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executing(t_list *commands)
{
	int	last_pid;

	//on recupere le pid du dernier enfant execute
	last_pid = pipex(commands);
	if (last_pid == -1)
		return (-1);
	//on attend la fin du process des enfants
	while (wait(NULL) != -1)
		;
	
	//on gerera surement les signaux juste apres
	
	return (0);
}
