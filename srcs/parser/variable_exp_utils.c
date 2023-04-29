/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:40:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/29 17:37:06 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_intersimplequote(char **str, t_chir *chir)
{
	int	l;
	int	j;
	int	k;
	int	count;

	l = -1;
	j = 0;
	k = 0;
	count = 0;
	while ((*str)[++l] && count <= chir->dollarcount)
	{
		if ((*str)[l] == '$')
			count++;
		if ((*str)[l] == '\'')
			j++;
	}
	while ((*str)[l])
	{
		if ((*str)[l] == '\'')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}

int	ft_interdoublequote(char **str, t_chir *chir) // ici
{
	int	l;
	int	j;
	int	k;
	int	count;

	l = -1;
	j = 0;
	k = 0;
	count = 0;
	while ((*str)[++l] && count <= chir->dollarcount)
	{
		if ((*str)[l] == '$')
			count++;
		if ((*str)[l] == '\"')
			j++;
	}
	while ((*str)[l])
	{
		if ((*str)[l] == '\"')
			k++;
		l++;
	}
	if (k % 2 == 0 && j % 2 == 0)
		return (0);
	return (1);
}

int	ft_whocamefirst(char **str, t_chir *chir) // ici
{
	int	l;
	int	j;
	int	count;

	l = -1;
	j = 0;
	count = 0;
	while ((*str)[++l] && count <= chir->dollarcount)
	{
		if ((*str)[l] == '$')
			count++;
		if ((*str)[l] == '\"')
			j = 2;
		if ((*str)[l] == '\'')
			j = 1;
	}
	if (j == 1)
		return (1);
	return (0);
}

char	ms_isalnum_(char s)
{
	if (ft_isalnum(s) == 1 || s == '_')
		return (1);
	else if (s == '?')
		return (2);
	else if (s == '\"' || s == '\'')
		return (3);
	else
		return (0);
}

int	ms_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


t_env	*ft_isenv(t_env *env, char *tofind, t_chir *chir)
{
	int		i;
	int		str;

	i = 0;
	str = 0;
	while (env != NULL)
	{
		str = ms_strcmp(env->name, tofind);
		if (str == 0)
		{
			chir->isenv = 1;
			return (env);
		}
		env = env->next;
	}
	chir->isenv = 0;
	return (NULL);
}
