/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:40:01 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/07 16:40:11 by nwyseur          ###   ########.fr       */
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

int	ms_strlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

t_env	*ft_isenv(t_env *env, char *tofind)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env->next != NULL)
	{
		str = ft_strnstr(env->name, tofind, ft_strlen(tofind));
		if (str != NULL)
			return (env);
		env = env->next;
	}
	return (NULL);
}
