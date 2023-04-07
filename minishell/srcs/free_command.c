/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/07 16:01:09 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_string_array(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_redirect(void *content)
{
	t_redirect *redirect;

	if (!content)
		return ;
	redirect = (t_redirect *)content;
	free(redirect->file);
	free(redirect);
}

void	free_command(void *content)
{
	t_command *cmd;

	if (!content)
		return ;
	cmd = (t_command *)content;
	ft_lstclear(&cmd->redirects, free_redirect);
	ft_free_string_array(cmd->args);
	free(cmd);
}

void	free_commands(t_list **commands)
{
	if (!commands || !*commands)
		return ;
	ft_lstclear(commands, free_command);

}
