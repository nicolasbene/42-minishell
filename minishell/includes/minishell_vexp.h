/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_vexp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/15 17:13:26 by nwyseur          ###   ########.fr       */
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
	int		totreat;
	int		isenv;
	char	sep;
	char	*varname;
	char	*varcont;

}	t_chir;

void	ft_variable_exp(t_cmd *cmd, t_env *env);
void	ft_exp_usecases(t_cmd *cmd, t_chir *chir, t_env *env);
int		ft_manage_var(t_cmd *cmd, t_chir *chir, t_env *env);
void	ft_init_chir(t_cmd *cmd, t_chir *chir, t_env *env, int j);
char	*ft_lookintoenv(t_env *env, t_chir *chir);
void	ft_switchvar(t_cmd *cmd, t_chir *chir);

// utils
int		ft_lookfor(char *str, int c);
void	ms_swap(t_cmd *cmd, t_chir *chir, char *new);
char	ms_isep(char *s);
char	ms_isalnum_(char s);
int		ms_strlen(char *s, char c);
t_env	*ft_isenv(t_env *env, char *tofind, t_chir *chir);
void	ft_istreat(t_cmd *cmd, t_chir *chir);
int		ft_intersimplequote(t_cmd *cmd, t_chir *chir);

// split
char	**ms_split(t_cmd *cmd);
void	ms_wordcount(char **arg, int *wc);
int		ms_wordcount_i(char *arg, int *wc);
int		ft_wordlen(char *s);
int		ms_passquote(char *arg, char c);
char	*ft_copyword(char const *s, int len, char **sstr, int j);
void	ft_strfree(char **sstr, int j);

// redir
void	ft_exp_rd(t_rdlist *rd, t_env *env);
void	ft_exp_redircases(t_rdlist *rd, t_chir *chir, t_env *env);
int		ft_intersimplequoterd(t_rdlist *rd);
void	ft_istreatrd(t_rdlist *rd, t_chir *chir);
void	ms_swaprd(t_rdlist *rd, char *new);
int		ft_manage_varrd(t_rdlist *rd, t_chir *chir, t_env *env);
void	ft_init_chirrd(t_rdlist *rd, t_chir *chir, t_env *env, int j);
void	ft_switchvarrd(t_rdlist *rd, t_chir *chir);

#endif