/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:07:44 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/30 18:24:11 by nwyseur          ###   ########.fr       */
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

enum	e_cmdtype
{
	CMD_CMD,
	CMD_PIPE,
	CMD_ERR,
};

typedef struct s_list
{
	char			*str;
	struct s_list	*next;

}	t_list;

typedef struct s_cmd
{
	enum e_cmdtype	type;
	t_list			*arg;
	t_list			*rd;
	struct s_cmd	*next;

}	t_cmd;

#endif