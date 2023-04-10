/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:39:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/10 18:07:36 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_switchvar(t_cmd *cmd, t_chir *chir) // revvoir les ++ et tout
{
	char	*new;
	int		len;
	int		k;
	int		j;

	len = ft_strlen(cmd->arg[chir->i]) + chir->lencont - (chir->lenvar + 1);
	printf("[LEN] %i\n", len);
	new = malloc((len + 1) * sizeof(char));
	new[len] = '\0';
	k = -1;
	j = -1;
	while (cmd->arg[chir->i][++k] != '$')
		new[k] = cmd->arg[chir->i][k];
	while (chir->varcont[++j] != '\0')
		new[k + j] = chir->varcont[j];
	j = k + j;
	printf("[J] %i\n", j);
	k = k + chir->lenvar;
	while (cmd->arg[chir->i][++k] != '\0') //attention ++ pas sur
	{
		new[j] = cmd->arg[chir->i][k];
		j++;
	}
	ms_swap(cmd, chir, new);
}

char	*ft_lookintoenv(t_env *env, t_chir *chir)
{
	t_env	*buff;

	buff = ft_isenv(env, chir->varname);
	free(chir->varname);
	if (buff == NULL)
		return (NULL); // gerer la remontee des NULL
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
	chir->posdollar = j;
	j++;
	chir->sep = ms_isep(&cmd->arg[chir->i][j]);
	chir->lenvar = ms_strlen(&cmd->arg[chir->i][j], chir->sep); // il y a eu correction ici
	chir->varname = calloc((chir->lenvar + 1), sizeof(char));
	while (cmd->arg[chir->i][j] != chir->sep && cmd->arg[chir->i][j] != '\0')
	{
		chir->varname[k] = cmd->arg[chir->i][j];
		k++;
		j++;
	}
	chir->varcont = ft_lookintoenv(env, chir); // return NULL
	printf("\n[VARCONT] %s\n", chir->varcont); // LA
	chir->lencont = ft_strlen(chir->varcont);
	ft_switchvar(cmd, chir);
}

void	ft_exp_usecases(t_cmd *cmd, t_chir *chir, t_env *env)
{
	if (ft_lookfor(cmd->arg[chir->i], 34) == 0 && ft_lookfor(cmd->arg[chir->i], 39) == 0)
		ft_manage_var(cmd, chir, env);
}

void	ft_variable_exp(t_cmd *cmd, t_env *env)
{
	t_chir	chir;
	int		j;

	chir.i = 0;
	while (cmd->arg[chir.i] != NULL)
	{
		printf("\nGRAND CHIEN DE LA CASSE\n");
		j = 0;
		while (cmd->arg[chir.i][j] != '\0')
		{
			printf("%i", j);
			if (cmd->arg[chir.i][j] == '$')
			{
				printf("dans le if: %i", j);
				ft_exp_usecases(cmd, &chir, env);
				j = chir.posdollar;
			}
			else
				j++;
		}
		chir.i++;
	}
}
