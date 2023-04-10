/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/10 18:01:32 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

t_env	*ft_initlistenv(void)
{
	t_env	*new;

	new = (t_env *)malloc(1 * sizeof(t_env));
	{
		new->name = "nom";
		new->content = "Nicolas";
	}
	new->next = NULL;
	return (new);
}

int	main(void)
{
	t_mst		*mst;
	t_mst		*tmp;
	t_cmd		*cmd;
	t_cmd		*tmpcmd;
	t_cmd		*tmpcmdbis;
	t_rdlist	*tmprd;
	t_env		*evr;
	int		i;


	evr = ft_initlistenv();
	mst = ft_lexer_main("bonjour je suis yo$nom.yo | comment vas tu | whats up brandon");
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
			printf("/");
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
	printf("\n-------------------\n");
	tmpcmdbis = tmpcmd;
	ft_variable_exp(tmpcmdbis, evr);
	while (tmpcmdbis != NULL)
	{
		i = 0;
		printf("\nargs:");
		while (tmpcmdbis->arg[i])
		{
			printf("%s ", tmpcmdbis->arg[i]);
			printf("/");
			i++;
		}
		tmprd = tmpcmdbis->rd;
		if (tmprd != NULL)
		{
			while (tmprd != NULL)
			{
				printf("\nRDTYPE: %i - FILE: %s", tmprd->type, tmprd->str);
				tmprd = tmprd->next;
			}
		}
		tmpcmdbis = tmpcmdbis->next;
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