/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:30 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/15 15:29:19 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_exp_redir(t_rdlist *rd, t_env *env)
{
	int	j;

	while (rd != NULL)
	{
		j = 0;
		while (rd->str[j] != '\0')
		{
			if (rd->str[j] == '$')
			{
				chir.posdollar = j;
				ft_exp_usecases(cmd, &chir, env);
				j = chir.posdollar;
			}
			else
				j++;
		}
	}
}