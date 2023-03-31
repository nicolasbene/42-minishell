/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/03/31 18:24:09 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"

int	main(void)
{
	t_mslex	*mslex;
	t_mst	*mst;
	t_mst	*tmp;

	mslex = ft_init_lexer("<< <");
	mst = ft_lexer_next_token(mslex);
	while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	{
		ft_mslstokenadd_back(&mst, ft_lexer_next_token(mslex));
	}
	free(mslex);
	tmp = mst;
	while (mst->next != NULL)
	{
		printf("TOKEN: %i & str: %s\n", mst->type, mst->value);
		mst = mst->next;
	}
	if (ft_syntax_check(tmp) != 0)
		return (printf("non\n"),(0));
	ft_mslstokenclear(&tmp);
	return (printf("oui\n"),(1));
}
