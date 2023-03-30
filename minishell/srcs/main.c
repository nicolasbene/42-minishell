/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/30 11:27:02 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_lexer.h"

int	main(void)
{
	t_mslex	*mslex;
	t_mst	*mst;

	mslex = ft_init_lexer("bonjour @ < jesuis'nicolas'  file1 | au revoir");
	mst = ft_lexer_next_token(mslex);
	while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	{
		ft_mslstokenadd_back(&mst, ft_lexer_next_token(mslex));
	}
	while (mst->next != NULL)
	{
		printf("TOKEN: %i & str: %s\n", mst->type, mst->value);
		mst = mst->next;
	}
	return (0);
}
