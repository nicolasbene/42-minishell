/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:42 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/17 16:16:49 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

// Permet de gerer les ' et " dans le lexing du mot;
char	*ft_lexer_parse_quote(t_mslex *mslex, char *value, int c)
{
	value = ft_strjoinchara(value, mslex->c);
	if (!value)
		return (NULL);
	ft_lexer_advance(mslex);
	while (mslex->c != c)
	{
		value = ft_strjoinchara(value, mslex->c);
		if (!value)
			return (NULL);
		ft_lexer_advance(mslex);
	}
	return (value);
}

// Permet de parser et return le mot entier quand le ttoken est un mot;
t_mst	*ft_lexer_parse_word(t_mslex *mslex)
{
	char	*value;

	value = ft_calloc(1, sizeof(char));
	if (!value)
		return (NULL);
	while (ft_ischara(mslex->c) == 1)
	{
		if (mslex->c == 39 && ft_strchrms(&mslex->str[mslex->i + 1], 39) == 1)
			value = ft_lexer_parse_quote(mslex, value, 39);
		else if (mslex->c == 39
			&& ft_strchrms(&mslex->str[mslex->i + 1], 39) == 0)
			return (ft_lexer_advance(mslex), ft_init_token("'", TOKEN_LQ));
		if (mslex->c == 34 && ft_strchrms(&mslex->str[mslex->i + 1], 34) == 1)
			value = ft_lexer_parse_quote(mslex, value, 34);
		else if (mslex->c == 34
			&& ft_strchrms(&mslex->str[mslex->i + 1], 34) == 0)
			return (ft_lexer_advance(mslex), ft_init_token("\"", TOKEN_LQQ));
		if (!value)
			return (NULL);
		value = ft_strjoinchara(value, mslex->c);
		if (!value)
			return (NULL);
		ft_lexer_advance(mslex);
	}
	return (ft_init_token(value, TOKEN_WORD));
}

// Va chercher le prochain token dans la str;
t_mst	*ft_lexer_next_token(t_mslex *mslex)
{
	while (mslex->c != '\0')
	{
		if (ft_ischara(mslex->c) == 1)
			return (ft_lexer_parse_word(mslex));
		if (mslex->c == '|' || mslex->c == '>' || mslex->c == '<')
			return (ft_lexer_next_token_suite(mslex));
		if ((mslex->c >= 9 && mslex->c <= 13) || mslex->c == 32)
			ft_lexer_skip_blank(mslex);
	}
	return (ft_init_token(0, TOKEN_EOF));
}

t_mst	*ft_lexer_next_token_suite(t_mslex *mslex)
{
	if (mslex->c == '|')
	{
		if (ft_lexer_peek(mslex, 1) == '|')
			return (ft_lexer_advance(mslex),
				ft_lexer_adv_ret(mslex, ft_init_token("||", TOKEN_PP)));
		return (ft_lexer_adv_ret(mslex, ft_init_token("|", TOKEN_PIPE)));
	}
	if (mslex->c == '<')
	{
		if (ft_lexer_peek(mslex, 1) == '<')
			return (ft_lexer_advance(mslex),
				ft_lexer_adv_ret(mslex, ft_init_token("<<", TOKEN_LL)));
		return (ft_lexer_adv_ret(mslex, ft_init_token("<", TOKEN_L)));
	}
	if (mslex->c == '>')
	{
		if (ft_lexer_peek(mslex, 1) == '>')
			return (ft_lexer_advance(mslex),
				ft_lexer_adv_ret(mslex, ft_init_token(">>", TOKEN_GG)));
		return (ft_lexer_adv_ret(mslex, ft_init_token(">", TOKEN_G)));
	}
	return (NULL);
}

// fonction main pour le lexer
t_mst	*ft_lexer_main(char *str)
{
	t_mslex	*mslex;
	t_mst	*mst;
	t_mst	*new;

	mslex = ft_init_lexer(str);
	if (!mslex)
		return (NULL);
	mst = ft_lexer_next_token(mslex);
	if (!mst)
		return (free(mslex), NULL);
	while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	{
		new = ft_lexer_next_token(mslex);
		if (!new)
			return (free(mslex), ft_mslstokenclear(&mst), NULL);
		ft_mslstokenadd_back(&mst, new);
	}
	free(mslex);
	return (mst);
}
