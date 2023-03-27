/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:24:59 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/27 17:07:53 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LEXER_H
# define MINISHELL_LEXER_H

# include "minishell_tokens.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct lexer_struct
{
	char	*str;
	char	c;
	int		i;
}	t_mslex;

t_mslex	*ft_init_lexer(char *str);
void	ft_lexer_avance(t_mslex *mslex);
t_mst	*ft_lexer_next_token(t_mslex *mslex);

#endif