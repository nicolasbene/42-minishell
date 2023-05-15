/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:16:16 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:50 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

// void	free_env(t_env *env)
// {
// 	if (env)
// 	{
// 		free(env->name);
// 		free(env->content);
// 		free(env);
// 	}
// }

// void	free_envs(t_env **envs)
// {
// 	t_env	*tmp;

// 	if (!envs || !*envs)
// 		return ;
// 	while (*envs)
// 	{
// 		tmp = *envs;
// 		*envs = (*envs)->next;
// 		free_env(tmp);
// 	}
// }

void free_envs(t_env *env)
{
    t_env *curr;

    while (env != NULL)
    {
        curr = env;
        env = env->next;
        free(curr->name);
        free(curr->content);
        free(curr);
    }
}
