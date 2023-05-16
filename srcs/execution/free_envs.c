/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:16:16 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/16 10:44:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	free_env(t_env *env)
{
	if (env)
	{
		free(env->name);
		free(env->content);
		free(env);
	}
}

void	free_envs(t_env *env)
{
	t_env	*curr;

	if (!env)
		return ;
	while (env != NULL)
	{
		curr = env;
		env = env->next;
		free(curr->name);
		free(curr->content);
		free(curr);
	}
}
