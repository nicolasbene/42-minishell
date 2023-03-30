/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:42 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/30 11:49:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_lexer.h"

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
		if (mslex->c == '|')
			return (ft_lexer_adv_ret(mslex, ft_init_token("|", TOKEN_PIPE)));
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
		if ((mslex->c >= 9 && mslex->c <= 13) || mslex->c == 32)
			ft_lexer_skip_blank(mslex);
	}
	return (ft_init_token(0, TOKEN_EOF));
}

// fonction main pour le lexer
t_mst	*ft_lexer_main(char *str)
{
	t_mslex	*mslex;
	t_mst	*mst;

	mslex = ft_init_lexer(str);
	mst = ft_lexer_next_token(mslex);
	while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	{
		ft_mslstokenadd_back(&mst, ft_lexer_next_token(mslex));
	}
	return (mst);
}
