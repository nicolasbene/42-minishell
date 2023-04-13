/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:40:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/11 15:55:57 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

int	ft_lookfor(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (1);
	else
		return (0);
}

void	ms_swap(t_cmd *cmd, t_chir *chir, char *new)
{
	char	*tmp;

	tmp = cmd->arg[chir->i];
	cmd->arg[chir->i] = new;
}

char	ms_isep(char *s)
{
	int	i;

	i = 0;
	while (ft_isalnum(s[i]) == 1 || s[i] == '_')
		i++;
	return (s[i]);
}

int	ms_strlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

void	ft_istreat(t_cmd *cmd, t_chir *chir)
{
	int	l;

	l = 0;
	while (cmd->arg[chir->i][l] && cmd->arg[chir->i][l] != '$')
		l++;
	if (cmd->arg[chir->i][l] == '$' && cmd->arg[chir->i][l + 1] == '\"')
		chir->totreat = 0;
	else
		chir->totreat = 1;
}

int	ft_intersimplequote(t_cmd *cmd, t_chir *chir)
{
	int	l;
	int	j;
	int	k;

	l = 0;
	j = 0;
	k = 0;
	while (cmd->arg[chir->i][l] && cmd->arg[chir->i][l] != '$')
	{
		if (cmd->arg[chir->i][l] == '\'')
			j++;
		l++;
	}
	while (cmd->arg[chir->i][l])
	{
		if (cmd->arg[chir->i][l] == '\'')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}


int	ms_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


t_env	*ft_isenv(t_env *env, char *tofind)
{
	int		i;
	int		str;

	i = 0;
	str = 0;
	printf("\n[VARNAME] %s\n", tofind); // LA
	while (env != NULL) // au lieu de env->next != NULL
	{
		str = ms_strcmp(env->name, tofind);
		if (str == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

// str = ft_strnstr(env->name, tofind, ft_strlen(tofind));