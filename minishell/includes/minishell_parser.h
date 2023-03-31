/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:07:44 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/31 18:17:35 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_H
# define MINISHELL_PARSER_H

# include "minishell_lexer.h"
# include "minishell_tokens.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

enum	e_rdtype
{
	RD_INF,
	RD_OUT,
	RD_APP,
	RD_HERE,
};

typedef enum e_errtype
{
	NO_ERR,
	SYNTAX_ERR,
	PIPE_ERR,
	RD_ERR,
}	t_err;

typedef struct s_rdlist
{
	enum e_rdtype	type;
	char			*str;
	struct s_rdlist	*next;

}	t_rdlist;

typedef struct s_cmd
{
	int				fd[2];
	char			**arg;
	t_rdlist		*rd;
	struct s_cmd	*next;

}	t_cmd;

#endif