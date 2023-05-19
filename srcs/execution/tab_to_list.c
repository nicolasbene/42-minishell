/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:18:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/19 11:18:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

t_env	*tab_to_list(char **envp)
{
	t_env	*envs;
	int		i;

	i = 0;
	envs = NULL;
	while (envp[i])
	{
		envs = add_node_env(envs, envp[i]);
		i++;
	}
	return (envs);
}
