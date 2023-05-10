/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_includes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:17:49 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/10 11:34:16 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_INCLUDES_H
# define MINISHELL_INCLUDES_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <linux/limits.h>
# include <errno.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/wait.h>

# include <signal.h>

//stat pour avoir les infos sur le fichier notamment si c un repretoir
# include <sys/stat.h>

//rd_out.c
# include <stdbool.h>

# include "minishell_tokens.h"
# include "minishell_lexer.h"
# include "minishell_parser.h"
# include "minishell_vexp.h"
# include "minishell_exec.h"

#endif