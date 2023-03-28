/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:42 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/28 18:36:56 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_lexer.h"

t_mslex	*ft_init_lexer(char *str)
{
	t_mslex	*mslex;

	mslex = (t_mslex *)malloc(1 * sizeof(t_mslex));
	mslex->str = str;
	mslex->str_size = ft_strlen(str);
	mslex->i = 0;
	mslex->c = str[mslex->i];
	return (mslex);
}

void	ft_lexer_advance(t_mslex *mslex)
{
	if (mslex->i < mslex->str_size && mslex->c != '\0')
	{
		mslex->i++;
		mslex->c = mslex->str[mslex->i];
	}
}

t_mst	*ft_lexer_adv_ret(t_mslex *mslex, t_mst *mst)
{
	ft_lexer_advance(mslex);
	return (mst);
}

char	ft_lexer_peek(t_mslex *mslex, int offset)
{
	if (mslex->i + offset <= mslex->str_size)
		return (mslex->str[mslex->i + offset]);
	else
		return (mslex->str[mslex->str_size]);
}

void	ft_lexer_skip_blank(t_mslex *mslex)
{
	while ((mslex->c >= 9 && mslex->c <= 13) || mslex->c == 32)
		ft_lexer_advance(mslex);
}

t_mst	*ft_lexer_parse_word(t_mslex *mslex)
{
	char	*value;

	value = ft_calloc(1, sizeof(char));
	if (!value)
		return (NULL);
	while (ft_isalnum(mslex->c))
	{
		value = ft_strjoinchara(value, mslex->c);
		if (!value)
			return (NULL);
		ft_lexer_advance(mslex);
	}
	return (ft_init_token(value, TOKEN_WORD));
}

// checker pourquoi il avance de 1 avant de return surtout pour le isalnum;
t_mst	*ft_lexer_next_token(t_mslex *mslex)
{
	while (mslex->c != '\0')
	{
		if (ft_isalnum(mslex->c))
			return (ft_lexer_adv_ret(mslex, ft_lexer_parse_word(mslex)));
		if (mslex->c == '|')
			return (ft_lexer_adv_ret(mslex, ft_init_token("|", TOKEN_PIPE)));
		if (mslex->c == '<')
		{
			if (ft_lexer_peek(mslex, 1) == '<')
				return (ft_lexer_adv_ret(mslex, ft_init_token("<<", TOKEN_LL)));
			return (ft_lexer_adv_ret(mslex, ft_init_token("<", TOKEN_L)));
		}
		if (mslex->c == '>')
		{
			if (ft_lexer_peek(mslex, 1) == '>')
				return (ft_lexer_adv_ret(mslex, ft_init_token(">>", TOKEN_LL)));
			return (ft_lexer_adv_ret(mslex, ft_init_token(">", TOKEN_L)));
		}
		if ((mslex->c >= 9 && mslex->c <= 13) || mslex->c == 32)
			ft_lexer_skip_blank(mslex);
	}
	return (ft_init_token(0, TOKEN_EOF));
}
