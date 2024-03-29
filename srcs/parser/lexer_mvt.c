/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:28:36 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/26 15:22:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

// Initialisation de la structure qui va nous servir a analyser la str
t_mslex	*ft_init_lexer(char *str)
{
	t_mslex	*mslex;

	mslex = (t_mslex *)malloc(1 * sizeof(t_mslex));
	if (mslex == NULL)
		return (NULL);
	mslex->str = str;
	mslex->str_size = ft_strlen(str);
	mslex->i = 0;
	mslex->c = str[mslex->i];
	return (mslex);
}

// Permet d'avancer de 1 dans la chaine de caractere et d'update la struct
void	ft_lexer_advance(t_mslex *mslex)
{
	if (mslex->i < (int)mslex->str_size && mslex->c != '\0')
	{
		mslex->i++;
		mslex->c = mslex->str[mslex->i];
	}
}

/* Permet d'avancer de 1 dans la chaine de caractere 
	et de return la liste chainee de token */
t_mst	*ft_lexer_adv_ret(t_mslex *mslex, t_mst *mst)
{
	ft_lexer_advance(mslex);
	return (mst);
}

// Permet d'aller regarder sur la chaine a X cases
char	ft_lexer_peek(t_mslex *mslex, int offset)
{
	if (mslex->i + offset <= (int)mslex->str_size)
		return (mslex->str[mslex->i + offset]);
	else
		return (mslex->str[mslex->str_size]);
}

// Permet de skip les whitespaces
void	ft_lexer_skip_blank(t_mslex *mslex)
{
	while ((mslex->c >= 9 && mslex->c <= 13) || mslex->c == 32)
		ft_lexer_advance(mslex);
}
