/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:39:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/13 16:15:57 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_switchvar(t_cmd *cmd, t_chir *chir)
{
	char	*new;
	int		len;
	int		k;
	int		j;

	len = ft_strlen(cmd->arg[chir->i]) + chir->lencont - (chir->lenvar + 1);
	new = malloc((len + 1) * sizeof(char));
	new[len] = '\0';
	k = -1;
	j = -1;
	while (cmd->arg[chir->i][++k] != '$')
		new[k] = cmd->arg[chir->i][k];
	while (chir->varcont[++j] != '\0')
		new[k + j] = chir->varcont[j];
	j = k + j;
	k = k + chir->lenvar;
	while (cmd->arg[chir->i][++k] != '\0')
	{
		new[j] = cmd->arg[chir->i][k];
		j++;
	}
	ms_swap(cmd, chir, new);
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

void	ft_manage_var(t_cmd *cmd, t_chir *chir, t_env *env)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (cmd->arg[chir->i][j] != '$')
		j++;
	j++;
	chir->sep = ms_isep(&cmd->arg[chir->i][j]);
	chir->lenvar = ms_strlen(&cmd->arg[chir->i][j], chir->sep);
	chir->varname = calloc((chir->lenvar + 1), sizeof(char));
	while (cmd->arg[chir->i][j] != chir->sep && cmd->arg[chir->i][j] != '\0')
	{
		chir->varname[k] = cmd->arg[chir->i][j];
		k++;
		j++;
	}
	chir->varcont = ft_lookintoenv(env, chir);
	printf("\n[VARCONT] %s\n", chir->varcont); // LA
	chir->lencont = ft_strlen(chir->varcont);
	ft_switchvar(cmd, chir);
	if (chir->totreat == 0)
		free(chir->varcont);
}

void	ft_exp_usecases(t_cmd *cmd, t_chir *chir, t_env *env)
{
	if (ft_lookfor(cmd->arg[chir->i], 34) == 0
		&& ft_lookfor(cmd->arg[chir->i], 39) == 0)
	{
		chir->totreat = 1;
		ft_manage_var(cmd, chir, env);
	}
	else if (ft_lookfor(cmd->arg[chir->i], 39) == 1)
	{
		if (ft_intersimplequote(cmd, chir) == 1)
		{
			chir->posdollar++;
			return ;
		}
		ft_istreat(cmd, chir);
		ft_manage_var(cmd, chir, env);
	}
	else if (ft_lookfor(cmd->arg[chir->i], 34) == 1)
	{
		ft_istreat(cmd, chir);
		ft_manage_var(cmd, chir, env);
	}
	else
		chir->posdollar++;
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
				ft_exp_usecases(cmd, &chir, env);
				j = chir.posdollar;
			}
			else
				j++;
		}
		chir.i++;
	}
	cmd->arg = ms_split(cmd);
}
