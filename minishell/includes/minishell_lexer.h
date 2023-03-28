/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:24:59 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/28 17:40:55 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LEXER_H
# define MINISHELL_LEXER_H

# include "minishell_tokens.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct lexer_struct
{
	char	*str;
	size_t	str_size;
	char	c;
	int		i;
}	t_mslex;

t_mslex	*ft_init_lexer(char *str);
void	ft_lexer_advance(t_mslex *mslex);
t_mst	*ft_lexer_adv_ret(t_mslex *mslex, t_mst *mst);
char	ft_lexer_peek(t_mslex *mslex, int offset);
void	ft_lexer_skip_blank(t_mslex *mslex);
t_mst	*ft_lexer_next_token(t_mslex *mslex);
t_mst	*ft_lexer_parse_word(t_mslex *mslex);

/* Utils */

char	*ft_strjoinchara(char *s1, char c);

#endif