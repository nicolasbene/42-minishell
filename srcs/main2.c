/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:28:57 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/28 14:45:46 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

t_minishell	g_minishell;

#define STR1 "bonjour je suis YOyo \"$nom\" | comment vas tu | whats up brandon"
#define STR2 "bonjour je suis YOyo $nom | comment vas tu | whats up brandon"
#define STR3 "bonjour je suis YOyo$\"nom\".yo | comment vas tu | whats up brandon"
#define STR4 "bonjour je suis YOyo$names.yo | comment vas tu | whats up brandon"
#define STR5 "bonjour je suis YOyo '$nom'.yo | comment vas tu | whats up brandon"
#define STR6 "bonjour je suis YOyoRobert.yo | comment vas tu | whats up brandon"
#define STR7 "bonjour je suis YOyo$nom > $nom | comment vas tu | whats up brandon"
#define STR8 "bonjour je suis YOyo$? $nom | comment vas tu | whats up brandon"
#define STR9 "bonjour je suis YOyo\"$?\" $nom | comment vas tu | whats up brandon"
#define STR10 "bonjour je suis YOyo$?nom | comment vas tu | whats up brandon"
#define STR11 "bonjour je suis YOyo\"'$nom'\" | comment vas tu | whats up brandon"
#define STR12 "bonjour je suis YOyo'\"$nom'\"\" | comment vas tu | whats up brandon"
#define STR13 "bonjour je suis YOyo'\"$nom\"'\"$nom\" | comment vas tu | whats up brandon"
#define STR14 "bonjour je suis YOyo\"$nom\"\"$nom\" | comment vas tu | whats up brandon"
#define STR15 "$\"$\"$\"$\"$\"\""
#define STR16 "bonjour je suis YOyo'$nom'$nom | comment vas tu | whats up brandon"
#define STR17 "bonjour je suis YOyo $nom\"$nom\" | comment vas tu | whats up brandon"
#define STR18 "bonjour je suis YOyo\"$nom $nom\" | comment vas tu | whats up brandon"
#define STR19 "bonjour je suis YOyo $\"nom\"yo | comment vas tu | whats up brandon"
#define STR20 "bonjour je suis YOyo'\"$nom\"'rolandmagdane\"$nom\" | comment vas tu | whats up brandon"

t_env	*ft_initlistenv(void)
{
	t_env	*new;

	new = (t_env *)malloc(1 * sizeof(t_env));
	{
		new->name = "nom";
		new->content = "Nicolas Wyseur";
	}
	new->next = NULL;
	return (new);
}

t_env	*ft_initlistint(t_env *evr)
{
	t_env	*new;

	new = (t_env *)malloc(1 * sizeof(t_env));
	{
		new->name = "?";
		new->content = "123";
	}
	new->next = evr;
	return (new);
}

int	main(void)
{
	t_mst		*mst;
	t_mst		*tmp;
	t_cmd		*cmd;
	t_cmd		*tmpcmd;
	t_cmd		*tmpcmdbis;
	t_cmd		*tmpcmdter;
	t_rdlist	*tmprd;
	t_env		*evr;
	t_env		*evint;
	int		i;


	evr = ft_initlistenv();
	evint = ft_initlistint(evr);
	mst = ft_lexer_main(STR1);
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
	printf("\n1---------------------\n");
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
	printf("\n2-------------------\n");
	tmpcmdbis = tmpcmd;
	ft_variable_exp(tmpcmdbis, evint);
	tmpcmdter = tmpcmdbis;
	while (tmpcmdbis != NULL)
	{
		i = 0;
		printf("\nargs :");
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
	/* printf("\n3-------------------\n");
	ft_quote_mngt(tmpcmdter);
	while (tmpcmdter != NULL)
	{
		i = 0;
		printf("\nargs %s:", tmpcmdter->arg[i]);
		while (tmpcmdter->arg[i])
		{
			printf("%s ", tmpcmdter->arg[i]);
			printf("/");
			i++;
		}
		tmprd = tmpcmdter->rd;
		if (tmprd != NULL)
		{
			while (tmprd != NULL)
			{
				printf("\nRDTYPE: %i - FILE: %s", tmprd->type, tmprd->str);
				tmprd = tmprd->next;
			}
		}
		tmpcmdter = tmpcmdter->next;
	}
	*/
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