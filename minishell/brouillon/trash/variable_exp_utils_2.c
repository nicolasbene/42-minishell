/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:11:48 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/15 15:55:22 by nwyseur          ###   ########.fr       */
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

void	ms_swap(char *cmd, char *new)
{
	char	*tmp;

	tmp = cmd;
	cmd = new;
	//free(tmp);
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

void	ft_istreat(char *cmd, t_chir *chir)
{
	int	l;

	l = 0;
	while (cmd[l] && cmd[l] != '$')
		l++;
	if (cmd[l] == '$' && cmd[l + 1] == '\"')
		chir->totreat = 0;
	else
		chir->totreat = 1;
}