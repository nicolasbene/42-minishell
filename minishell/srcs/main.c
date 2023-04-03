/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/03 18:10:48 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"
#include "../includes/minishell_parser.h"

int	main(void)
{
	t_mslex	*mslex;
	t_mst	*mst;
	t_mst	*tmp;
	t_cmd	*cmd;
	int		i;

	mslex = ft_init_lexer("bonjour je suis < nicolas | > comment > alerte je suis billy");
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
		printf("non\n");
	else
		printf("oui\n");
	//ft_mslstokenclear(&tmp);
	printf("\n---------------------\n");
	////////
	cmd = ft_parser_struct(tmp);
	while (cmd != NULL)
	{
		i = 0;
		printf("args:");
		while (i < 3)
		{
			printf("%s ", cmd->arg[i]);
			i++;
		}
		if (cmd->rd != NULL)
		{
			while (cmd->rd != NULL)
			{
				printf("\nRDTYPE: %i - FILE: %s\n", cmd->rd->type, cmd->rd->str);
				cmd->rd = cmd->rd->next;
			}
		}
		cmd = cmd->next;
	}
}
