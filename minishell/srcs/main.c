/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/05 15:28:55 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

int	main(void)
{
	t_mst		*mst;
	t_mst		*tmp;
	t_cmd		*cmd;
	t_cmd		*tmpcmd;
	t_rdlist	*tmprd;
	int		i;

	mst = ft_lexer_main("bonjour je suis | comment > 'fuck test billy' | whats up brandon");
	if (mst == NULL)
		return (0);
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
	printf("\n---------------------\n");
	////////
	cmd = ft_parser_struct(tmp);
	if (cmd == NULL)
		return (0);
	tmpcmd = cmd;

	while (cmd != NULL)
	{
		i = 0;
		printf("\nargs:");
		while (cmd->arg[i])
		{
			printf("%s ", cmd->arg[i]);
			i++;
		}
		tmprd = cmd->rd;
		if (tmprd != NULL)
		{
			while (tmprd != NULL)
			{
				printf("\nRDTYPE: %i - FILE: %s", tmprd->type, tmprd->str);
				tmprd = tmprd->next;
			}
		}
		cmd = cmd->next;
	}
	ft_mslstokenclear(&tmp);
	ft_free_cmd(&tmpcmd);
	printf("\n");
}

	//mslex = ft_init_lexer("bonjour je suis | comment > 'fuck test billy' | whats up brandon");
	//mst = ft_lexer_next_token(mslex);
	//while (ft_msltokenlast(mst)->type != TOKEN_EOF)
	//{
	//	ft_mslstokenadd_back(&mst, ft_lexer_next_token(mslex));
	//}
	//free(mslex);