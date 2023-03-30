/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/30 14:07:23 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"

int	main(void)
{
	t_mslex	*mslex;
	t_mst	*mst;

	mslex = ft_init_lexer("bonjour @ < jesuis'nicolas' file1 |");
	mst = ft_lexer_next_token(mslex);
	while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	{
		ft_mslstokenadd_back(&mst, ft_lexer_next_token(mslex));
	}
	free(mslex);
	while (mst->next != NULL)
	{
		printf("TOKEN: %i & str: %s\n", mst->type, mst->value);
		mst = mst->next;
	}
	ft_mslstokenclear(&mst);
	return (0);
}
