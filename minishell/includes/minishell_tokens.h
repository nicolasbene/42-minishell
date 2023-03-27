/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokens.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:24:53 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/27 15:16:21 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKENS_H
# define MINISHELL_TOKENS_H

typedef struct ms_t_struct
{
	char *value;
	enum type
	{
		TOKEN_WORD,
		TOKEN_PIPE,
		TOKEN_G,
		TOKEN_GG,
		TOKEN_L,
		TOKEN_LL,
		TOKEN_QC,
		TOKEN_QQC,
	}
	;
} ms_t;



#endif