/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:17:30 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/15 17:20:39 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_switchvarrd(t_rdlist *rd, t_chir *chir)
{
	char	*new;
	int		len;
	int		k;
	int		j;

	len = ft_strlen(rd->str) + chir->lencont - (chir->lenvar + 1);
	new = malloc((len + 1) * sizeof(char));
	new[len] = '\0';
	k = -1;
	j = -1;
	while (rd->str[++k] != '$')
		new[k] = rd->str[k];
	while (chir->varcont[++j] != '\0')
		new[k + j] = chir->varcont[j];
	j = k + j;
	k = k + chir->lenvar;
	while (rd->str[++k] != '\0')
	{
		new[j] = rd->str[k];
		j++;
	}
	ms_swaprd(rd, new);
	if (chir->totreat == 1 && chir->isenv == 1)
		free(chir->varcont);
}

void	ft_init_chirrd(t_rdlist *rd, t_chir *chir, t_env *env, int j)
{
	int	k;

	k = 0;

	j++;
	if (ms_isalnum_(rd->str[j]) == 2)
		chir->sep = rd->str[j + 1];
	else
		chir->sep = ms_isep(&rd->str[j]);
	chir->lenvar = ms_strlen(&rd->str[j], chir->sep);
	chir->varname = calloc((chir->lenvar + 1), sizeof(char)); // malloc
	while (rd->str[j] != chir->sep && rd->str[j] != '\0')
	{
		chir->varname[k] = rd->str[j];
		k++;
		j++;
	}
	chir->varcont = ft_lookintoenv(env, chir);
	chir->lencont = ft_strlen(chir->varcont);
}

int	ft_manage_varrd(t_rdlist *rd, t_chir *chir, t_env *env)
{
	int		j;

	j = 0;
	while (rd->str[j] != '$')
		j++;
	if (ms_isalnum_(rd->str[j + 1]) == 0)
		return (chir->posdollar++);
	ft_init_chirrd(rd, chir, env, j);
	ft_switchvarrd(rd, chir);
	if (chir->totreat == 0)
		free(chir->varcont);
	return (1);
}

void	ft_exp_redircases(t_rdlist *rd, t_chir *chir, t_env *env)
{
	if (ft_lookfor(rd->str, 34) == 0
		&& ft_lookfor(rd->str, 39) == 0)
	{
		chir->totreat = 1;
		ft_manage_varrd(rd, chir, env);
	}
	else if (ft_lookfor(rd->str, 39) == 1)
	{
		if (ft_intersimplequoterd(rd) == 1)
		{
			chir->posdollar++;
			return ;
		}
		ft_istreatrd(rd, chir);
		ft_manage_varrd(rd, chir, env);
	}
	else if (ft_lookfor(rd->str, 34) == 1)
	{
		ft_istreatrd(rd, chir);
		ft_manage_varrd(rd, chir, env);
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
				ft_exp_redircases(rd, &chirii, env);
				j = chirii.posdollar;
			}
			else
				j++;
		}
		rd = rd->next;
	}
}
