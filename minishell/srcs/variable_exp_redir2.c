/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_redir2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:41:26 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/15 17:15:29 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

int	ft_intersimplequoterd(t_rdlist *rd)
{
	int	l;
	int	j;
	int	k;

	l = 0;
	j = 0;
	k = 0;
	while (rd->str[l] && rd->str[l] != '$')
	{
		if (rd->str[l] == '\'')
			j++;
		l++;
	}
	while (rd->str[l])
	{
		if (rd->str[l] == '\'')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}

void	ft_istreatrd(t_rdlist *rd, t_chir *chir)
{
	int	l;

	l = 0;
	while (rd->str[l] && rd->str[l] != '$')
		l++;
	if (rd->str[l] == '$' && rd->str[l + 1] == '\"')
		chir->totreat = 0;
	else
		chir->totreat = 1;
}

void	ms_swaprd(t_rdlist *rd, char *new)
{
	char	*tmp;

	tmp = rd->str;
	rd->str = new;
	free(tmp);
}
