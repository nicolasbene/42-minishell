/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_vexp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/29 17:36:58 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_VEXP_H
# define MINISHELL_VEXP_H

# include "minishell_includes.h"

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_chir
{
	int		lenvar;
	int		lencont;
	int		i;
	int		posdollar;
	int		dollarcount; // ici 
	int		totreat;
	int		isenv;
	char	sep;
	char	*varname;
	char	*varcont;

}	t_chir;

typedef struct s_quote
{
	int		i;
	int		lenword;
	int		wordpos;
	char	*word;

}	t_quote;

void	ft_variable_exp(t_cmd *cmd, t_env *env);
void	ft_exp_rd(t_rdlist *rd, t_env *env);
void	ft_exp_usecases(char **str, t_chir *chir, t_env *env);
int		ft_manage_var(char **str, t_chir *chir, t_env *env);
void	ft_init_chir(char **str, t_chir *chir, t_env *env, int j);
char	*ft_lookintoenv(t_env *env, t_chir *chir);
void	ft_switchvar(char **str, t_chir *chir, int l); // ici int l

// utils
int		ft_lookfor(char *str, int c);
void	ms_swap(char **str, char *new);
char	ms_isep(char *s);
char	ms_isalnum_(char s);
int		ms_strlen(char *s, char c);
t_env	*ft_isenv(t_env *env, char *tofind, t_chir *chir);
void	ft_istreat(char **str, t_chir *chir);
int		ft_intersimplequote(char **str, t_chir *chir); // ici chir
int		ft_interdoublequote(char **str, t_chir *chir); // ici
int		ft_whocamefirst(char **str, t_chir *chir); // ici
void	ft_both_quote(char **str, t_chir *chir, t_env *env);

// split
char	**ms_split(t_cmd *cmd);
void	ms_wordcount(char **arg, int *wc);
int		ms_wordcount_i(char *arg, int *wc);
int		ft_wordlen(char *s);
int		ms_passquote(char *arg, char c);
char	*ft_copyword(char const *s, int len, char **sstr, int j);
void	ft_strfree(char **sstr, int j);

// Quote management
void	ft_quote_mngt(t_cmd *cmd);
void	ft_quote_usecases(char **str, t_quote *quote, int type);
char	*ft_quotedup(char *src, int len);
int		ft_quotelen(char *str, int type);

#endif