/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:05:39 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/18 15:29:28 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_intosmpl(char **str, int pos)
{
	int	l;
	int	j;
	int	k;

	l = -1;
	j = 0;
	k = 0;
	while ((*str)[++l] && l <= pos)
	{
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

int	ft_intodbl(char **str, int pos)
{
	int	l;
	int	j;
	int	k;

	l = -1;
	j = 0;
	k = 0;
	while ((*str)[++l] && l <= pos)
	{
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

char	*ft_strjoinnbr(char *s1, char c)
{
	int		l_string;
	int		i;
	char	*new;

	i = 0;
	l_string = ft_strlen(s1) + 2;
	new = (char *)malloc(l_string * sizeof(char));
	if (!new)
		return (free(s1), NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	i++;
	new [i] = '\0';
	free(s1);
	return (new);
}

void	ft_switchquote_rd(t_rdlist *rd, t_quote *quote)
{
	char	*new;
	int		len;
	int		l;
	int		j;

	len = (int)ft_strlen(rd->str) - quote->nbrtodel;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return ;
	l = -1;
	j = 0;
	while (++l < len)
	{
		while (ft_istodel(j, quote) == 1)
			j++;
		new[l] = rd->str[j];
		if (rd->str[j] != '\0')
			j++;
	}
	new[l] = '\0';
	if (quote->quotedel != NULL)
		free (quote->quotedel);
	ms_swap(&rd->str, new);
}

void	ft_quote_mngt_rd(t_rdlist *rd)
{
	t_quote	quote;
	int		j;

	while (rd != NULL)
	{
		j = 0;
		quote.nbrtodel = 0;
		quote.quotedel = NULL;
		while (rd->str[j] != '\0')
		{
			if (rd->str[j] == 34 || rd->str[j] == 39)
				ft_isquotetodel(&rd->str,
					&quote, rd->str[j], j);
			j++;
		}
		ft_switchquote_rd(rd, &quote);
		rd = rd->next;
	}
}
