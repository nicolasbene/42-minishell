/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:42 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/27 17:04:50 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_tokens.h"
#include "minishell_lexer.h"

t_mslex	*ft_init_lexer(char *str)
{
	t_mslex	*mslex;

	mslex = (t_mslex *)malloc(1 * sizeof(t_mslex));
	mslex->str = str;
	mslex->i = 0;
	mslex->c = str[mslex->i];
	return (mslex);
}
