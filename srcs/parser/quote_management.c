/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:33:12 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/16 12:05:25 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	*ft_listtodel(t_quote *quote, int pos)
{
	int	*new;
	int	i;

	new = (int *)malloc(quote->nbrtodel * sizeof(int));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < quote->nbrtodel - 1)
		new[i] = quote->quotedel[i];
	new[i] = pos;
	if (quote->quotedel != NULL)
		free (quote->quotedel);
	return (new);
}

void	ft_isquotetodel(char **str, t_quote *quote, int type, int pos)
{
	if ((type == 34 && ft_intosmpl(str, pos) == 1)
		|| (type == 39 && ft_intodbl(str, pos) == 1))
		return ;
	else
	{
		quote->nbrtodel++;
		quote->quotedel = ft_listtodel(quote, pos);
	}
}

int	ft_istodel(int j, t_quote *quote)
{
	int	i;

	i = 0;
	while (i < quote->nbrtodel)
	{
		if (quote->quotedel[i] == j)
			return (1);
		i++;
	}
	return (0);
}

void	ft_switchquote(t_cmd *cmd, t_quote *quote)
{
	char	*new;
	int		len;
	int		l;
	int		j;

	len = (int)ft_strlen(cmd->arg[quote->i]) - quote->nbrtodel;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return ;
	l = -1;
	j = 0;
	while (++l < len)
	{
		while (ft_istodel(j, quote) == 1)
			j++;
		new[l] = cmd->arg[quote->i][j];
		if (cmd->arg[quote->i][j] != '\0')
			j++;
	}
	new[l] = '\0';
	if (quote->quotedel != NULL)
		free (quote->quotedel);
	ms_swap(&cmd->arg[quote->i], new);
}

void	ft_quote_mngt(t_cmd *cmd)
{
	t_quote	quote;
	int		j;

	quote.i = 0;
	while (cmd->arg[quote.i] != NULL)
	{
		j = 0;
		quote.nbrtodel = 0;
		quote.quotedel = NULL;
		while (cmd->arg[quote.i][j] != '\0')
		{
			if (cmd->arg[quote.i][j] == 34 || cmd->arg[quote.i][j] == 39)
				ft_isquotetodel(&cmd->arg[quote.i],
					&quote, cmd->arg[quote.i][j], j);
			j++;
		}
		ft_switchquote(cmd, &quote);
		quote.i++;
	}
}
