/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:39:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/18 15:53:45 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

void	ft_switchvar(char **str, t_chir *chir, int l)
{
	char	*new;
	int		len;
	int		k;
	int		j;

	len = ft_strlen((*str)) + chir->lencont - (chir->lenvar + 1);
	new = malloc((len + 1) * sizeof(char));
	new[len] = '\0';
	k = -1;
	j = -1;
	while (++k != l)
		new[k] = (*str)[k];
	while (chir->varcont[++j] != '\0')
		new[k + j] = chir->varcont[j];
	j = k + j;
	k = k + chir->lenvar;
	while ((*str)[++k] != '\0')
	{
		new[j] = (*str)[k];
		j++;
	}
	ms_swap(str, new);
	if (chir->totreat == 1 && chir->isenv == 1)
		free(chir->varcont);
}

void	ft_both_quote(char **str, t_chir *chir, t_env *env)
{
	int	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != 34 && (*str)[i] != 39)
		i++;
	if (ft_interdoublequote(str, chir) == 1
		&& ft_intersimplequote(str, chir) == 1
		&& ft_whocamefirst(str, chir) == 1)
	{
		ft_istreat(str, chir);
		ft_manage_var(str, chir, env);
		return ;
	}
	else if (ft_intersimplequote(str, chir) == 1)
	{
		chir->dollarcount++;
		chir->posdollar++;
		return ;
	}
	ft_istreat(str, chir);
	ft_manage_var(str, chir, env);
	return ;
}

void	ft_exp_usecases(char **str, t_chir *chir, t_env *env)
{
	if (ft_lookfor((*str), 34) == 0 && ft_lookfor((*str), 39) == 0)
	{
		chir->totreat = 1;
		ft_manage_var(str, chir, env);
	}
	else if (ft_lookfor((*str), 34) == 1 && ft_lookfor((*str), 39) == 1)
		ft_both_quote(str, chir, env);
	else if (ft_lookfor((*str), 39) == 1)
	{
		if (ft_intersimplequote(str, chir) == 1)
		{
			chir->dollarcount++;
			chir->posdollar++;
			return ;
		}
		ft_istreat(str, chir);
		ft_manage_var(str, chir, env);
	}
	else if (ft_lookfor((*str), 34) == 1)
	{
		ft_istreat(str, chir);
		ft_manage_var(str, chir, env);
	}
	else
		chir->posdollar++;
}

void	ft_exp_rd(t_rdlist *rd, t_env *env)
{
	t_chir	chirii;
	int		j;

	chirii.varname = NULL;
	chirii.varcont = NULL;
	while (rd != NULL)
	{
		j = 0;
		chirii.dollarcount = 0;
		while (rd->str[j] != '\0')
		{
			if (rd->str[j] == '$')
			{
				chirii.posdollar = j;
				ft_exp_usecases(&rd->str, &chirii, env);
				j = chirii.posdollar;
			}
			else
				j++;
		}
		rd = rd->next;
	}
}

void	ft_variable_exp(t_cmd *cmd, t_env *env)
{
	t_chir	chir;
	int		j;

	chir.i = 0;
	chir.varname = NULL;
	chir.varcont = NULL;
	while (cmd->arg[chir.i] != NULL)
	{
		j = 0;
		chir.dollarcount = 0;
		while (cmd->arg[chir.i][j] != '\0')
		{
			if (cmd->arg[chir.i][j] == '$')
			{
				chir.posdollar = j;
				ft_exp_usecases(&cmd->arg[chir.i], &chir, env);
				j = chir.posdollar;
			}
			else
				j++;
		}
		chir.i++;
	}
	ft_exp_rd(cmd->rd, env);
	cmd->arg = ms_split(cmd);
}
