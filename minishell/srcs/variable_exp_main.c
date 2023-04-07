/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:39:21 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/07 17:33:19 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_switchvar(t_cmd *cmd, char *toinc, int dollarlen, int i)
{
	char *new;

	new = malloc((ft_strlen(arg[i]) + ft_strlen(toinc)))
	//laaaaa
}

char	*ft_lookintoenv(t_env *env, char *tmp)
{
	char	*str;
	t_env	*buff;

	buff = ft_isenv(env, tmp);
	free(tmp);
	if (buff == NULL)
		return (NULL);
	else
		return (ft_strdup(env->content));

}

void	ft_replace_var(t_cmd *cmd, int i, t_env *env, char c)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (cmd->arg[i][j] != '$')
		j++;
	j++;
	tmp = malloc((ms_strlen(&cmd->arg[i][j], ' ') + 1) * sizeof(char));
	while (cmd->arg[i][j] != c && cmd->arg[i][j] != '\0')
	{
		tmp[k] = cmd->arg[i][j];
		k++;
		j++;
	}
	tmp[k] = '\0';
	tmp = ft_lookintoenv(env, tmp);
	ft_switchvar(cmd, tmp, k, i);
}

void	ft_exp_usecases(t_cmd *cmd, int i, t_env *env)
{
	if (ft_lookfor(cmd->arg[i], 34) == 0 && ft_lookfor(cmd->arg[i], 39) == 0)
		ft_replace_var(cmd, i, env, ' ');
}


t_cmd	*ft_variable_exp(t_cmd *cmd, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (cmd->arg[i] != NULL)
	{
		j = 0;
		while (cmd->arg[i][j] != '\0')
		{
			if (cmd->arg[i][j] == '$')
				ft_exp_usecases(cmd, i, env);
		}
	}
}