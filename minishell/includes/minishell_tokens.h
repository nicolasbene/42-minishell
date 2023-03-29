/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:24:53 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/29 11:55:26 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKENS_H
# define MINISHELL_TOKENS_H

# include "minishell_lexer.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

enum	e_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_G,
	TOKEN_GG,
	TOKEN_L,
	TOKEN_LL,
	TOKEN_QC,
	TOKEN_QQC,
	TOKEN_EOF,
};

typedef struct mst_struct
{
	char					*value;
	enum e_type				type;
	struct mst_struct		*next;
}	t_mst;

t_mst	*ft_init_token(char *value, int type);
void	ft_mslstokenclear(t_mst **lst);
void	ft_mslstokenadd_back(t_mst **lst, t_mst *new);
t_mst	*ft_msltokenlast(t_mst *lst);
int		ft_mslstokensize(t_mst *lst);

#endif