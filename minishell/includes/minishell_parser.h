/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:07:44 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/05 10:56:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_H
# define MINISHELL_PARSER_H

# include "minishell_includes.h"

enum	e_rdtype
{
	RD_INF = 4,
	RD_OUT = 2,
	RD_APP = 3,
	RD_HERE = 5,
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
	char			**arg;
	t_rdlist		*rd;
	struct s_cmd	*next;

}	t_cmd;

// Parser
// Syntax Checker
// t_cmd	*ft_main_parser(t_mst *mst);
int			ft_syntax_check(t_mst *mst);
int			ft_printerr(t_mst *tmp, int err);
int			ft_check_rd(t_mst *tmp);
int			ft_check_pipe(t_mst *tmp, t_mst *prev);

// Cmd List Creator
t_cmd		*ft_parser_struct(t_mst *mst);
t_cmd		*ft_cmd_maillon(t_mst **mst, int *nb);
void		ft_cmdlstokenadd_back(t_cmd **lst, t_cmd *new);
void		ft_rdlstokenadd_back(t_rdlist **lst, t_rdlist *new);
t_rdlist	*ft_init_rdlist(t_mst *mst, int *nb);
t_cmd		*ft_init_cmd(int *nb);
void		ft_cmd_size(t_mst *mst, int *nb);

// Parser Free
void		ft_free_cmd(t_cmd **lst);
void		ft_rdlstclear(t_rdlist **lst);
void		ft_free_list(t_cmd **cmd, t_mst **mst);

#endif