/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:52:51 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/27 18:13:30 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

int	ft_quotelen(char *str, int type)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != type)
		i++;
	return (i);
}

char	*ft_quotedup(char *src, int len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	if (ret)
	{
		ft_strlcpy(ret, src, len + 1);
		return (ret);
	}
	else
		return (0);
}

void	ft_quote_usecases(char **str, t_quote *quote, int type)
{
	size_t	len;
	int		i;
	int		j;
	char	*new;

	len = ft_strlen((*str));
	i = 0;
	while ((*str)[i] && (*str)[i] != type)
		i++;
	quote->wordpos = i;
	i++;
	quote->lenword = ft_quotelen(&(*str)[i], type);
	quote->word = ft_quotedup(&(*str)[i], quote->lenword);
	new = (char *)malloc((len - 2 + 1) * sizeof(char));
	if (!new)
		return ;
	j = -1;
	i = -1;
	while (++j < quote->wordpos)
		new[j] = (*str)[j];
	while (quote->word[++i])
		new[j + i] = quote->word[i];
	j = j + i;
	i = j + 2;
	while ((*str)[i])
	{
		new[j] = (*str)[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(*str);
	free(quote->word);
	(*str) = new;
}

void	ft_quote_mngt(t_cmd *cmd)
{
	t_quote	quote;
	int		j;

	quote.i = 0;
	while (cmd->arg[quote.i] != NULL)
	{
		j = 0;
		while (cmd->arg[quote.i][j] != '\0')
		{
			if (cmd->arg[quote.i][j] == 34 || cmd->arg[quote.i][j] == 39)
			{
				ft_quote_usecases(&cmd->arg[quote.i], &quote, cmd->arg[quote.i][j]);
				j = j + quote.lenword;
			}
			else
				j++;
		}
		quote.i++;
	}
}