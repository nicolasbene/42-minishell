/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:34:29 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/19 13:24:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	ft_isintostr(const char *s1, char c)
{
	size_t			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (0);
		i++;
	}
	return (1);
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
	chir->varname = ft_calloc((chir->lenvar + 1), sizeof(char));
	while ((*str)[j] != chir->sep && (*str)[j] != '\0')
		chir->varname[k++] = (*str)[j++];
	if (ft_strcmp(chir->varname, "?") == 0)
	{
		chir->varcont = ft_itoa(g_minishell.exit_status);
		chir->isenv = 1;
		free(chir->varname);
	}
	else
		chir->varcont = ft_lookintoenv(env, chir);
	chir->lencont = ft_strlen(chir->varcont);
	if (ft_isintostr(chir->varcont, '$') == 0)
		chir->posdollar = chir->posdollar + chir->lencont;
}

int	ft_manage_var(char **str, t_chir *chir, t_env *env)
{
	int		j;

	j = chir->posdollar;
	while ((*str)[j] != '$')
		j++;
	if (ms_isalnum_((*str)[j + 1]) == 0)
		return (chir->posdollar++);
	ft_init_chir(str, chir, env, j);
	ft_switchvar(str, chir, j);
	if (chir->totreat == 0)
		free(chir->varcont);
	return (1);
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
		return ("\0");
	else
		return (ft_strdup(buff->content));
}
