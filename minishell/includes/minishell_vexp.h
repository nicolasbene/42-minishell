/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_vexp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/10 17:03:55 by nwyseur          ###   ########.fr       */
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
	char	sep;
	char	*varname;
	char	*varcont;

}	t_chir;

void	ft_variable_exp(t_cmd *cmd, t_env *env);
void	ft_exp_usecases(t_cmd *cmd, t_chir *chir, t_env *env);
void	ft_manage_var(t_cmd *cmd, t_chir *chir, t_env *env);
char	*ft_lookintoenv(t_env *env, t_chir *chir);
void	ft_switchvar(t_cmd *cmd, t_chir *chir);

// utils
int		ft_lookfor(char *str, int c);
void	ms_swap(t_cmd *cmd, t_chir *chir, char *new);
char	ms_isep(char *s);
int		ms_strlen(char *s, char c);
t_env	*ft_isenv(t_env *env, char *tofind);

#endif