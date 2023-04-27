/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:39:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/27 14:21:57 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	ft_switchvar(char **str, t_chir *chir)
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
	while ((*str)[++k] != '$')
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

char	*ft_lookintoenv(t_env *env, t_chir *chir)
{
	t_env	*buff;

	if (chir->totreat == 1)
		buff = ft_isenv(env, chir->varname, chir);
	else
		return (chir->varname);
	free(chir->varname);
	chir->varname = NULL;
	if (buff == NULL)
		return ("\0"); // gerer la remontee des NULL
	else
		return (ft_strdup(buff->content));
}

void	ft_init_chir(char **str, t_chir *chir, t_env *env, int j)
{
	int	k;

	k = 0;

	j++;
	if (ms_isalnum_((*str)[j]) == 2)
		chir->sep = (*str)[j + 1];
	else
		chir->sep = ms_isep(&(*str)[j]);
	chir->lenvar = ms_strlen(&(*str)[j], chir->sep);
	chir->varname = calloc((chir->lenvar + 1), sizeof(char)); // malloc
	while ((*str)[j] != chir->sep && (*str)[j] != '\0')
	{
		chir->varname[k] = (*str)[j];
		k++;
		j++;
	}
	chir->varcont = ft_lookintoenv(env, chir);
	chir->lencont = ft_strlen(chir->varcont);
}

int	ft_manage_var(char **str, t_chir *chir, t_env *env)
{
	int		j;

	j = 0;
	while ((*str)[j] != '$')
		j++;
	if (ms_isalnum_((*str)[j + 1]) == 0)
		return (chir->posdollar++);
	ft_init_chir(str, chir, env, j);
	ft_switchvar(str, chir);
	if (chir->totreat == 0)
		free(chir->varcont);
	return (1);
}

void	ft_both_quote(char **str, t_chir *chir, t_env *env)
{
	int	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != 34 && (*str)[i] != 39)
		i++;
	if ((*str)[i] == 34)
	{
		ft_istreat(str, chir);
		ft_manage_var(str, chir, env);
	}
	else if ((*str)[i] == 39)
	{
		if (ft_intersimplequote(str) == 1)
		{
			chir->posdollar++;
			return ;
		}
		ft_istreat(str, chir);
		ft_manage_var(str, chir, env);
	}
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
		if (ft_intersimplequote(str) == 1)
		{
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

/*
int	ft_manage_var(t_cmd *cmd, t_chir *chir, t_env *env)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (cmd->arg[chir->i][j] != '$')
		j++;
	if (ms_isalnum_(cmd->arg[chir->i][j + 1]) == 0)
		return (chir->posdollar++);
	if (ms_isalnum_(cmd->arg[chir->i][j + 1]) == 2)
		return (chir->posdollar++); // a travailler
	j++;
	chir->sep = ms_isep(&cmd->arg[chir->i][j]);
	chir->lenvar = ms_strlen(&cmd->arg[chir->i][j], chir->sep);
	chir->varname = calloc((chir->lenvar + 1), sizeof(char)); // malloc
	while (cmd->arg[chir->i][j] != chir->sep && cmd->arg[chir->i][j] != '\0')
	{
		chir->varname[k] = cmd->arg[chir->i][j];
		k++;
		j++;
	}
	chir->varcont = ft_lookintoenv(env, chir);
	chir->lencont = ft_strlen(chir->varcont);
	ft_switchvar(cmd, chir);
	if (chir->totreat == 0)
		free(chir->varcont);
	return (1);
}
*/