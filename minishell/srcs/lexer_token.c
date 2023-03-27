/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:54:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/27 16:35:18 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_tokens.h"
#include "minishell_lexer.h"

t_mst	*ft_init_token(char *value, int type)
{
	t_mst	*new;

	new = (t_mst *)malloc(sizeof(t_mst) * 1);
	if (new == NULL)
		return (NULL);
	else
	{
		new->value = value;
		new->type = type;
	}
	new->next = NULL;
	return (new);
}
