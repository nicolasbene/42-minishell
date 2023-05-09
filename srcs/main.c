/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/09 11:14:26 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

t_minishell	g_minishell;

void	usage(char *prog_name)
{
	print_error("%s: too many arguments", prog_name, NULL);
}

char	*read_line(void)
{
	char	*line;

	line = readline("minishell> ");
	if (!line)
		return (NULL);
	else if (*line)
		add_history(line);
	return (line);
}

void	execute_shell_commands(void)
{
	char		*line;
	t_cmd		*commands;
	t_mst		*mst;

	commands = NULL;
	while (1)
	{
		line = read_line();
		if (!line)
			break ;
		if (line)
		{
			mst = ft_lexer_main(line);
			if (mst && mst->type == TOKEN_EOF)
				ft_mslstokenclear(&mst);
			else
				commands = ft_main_parser(mst); // ici
			// create_commands(&commands);
			if (commands)
				executing(commands);
			free_commands(commands);
		}
		free(line);
	}
	free_envs(&g_minishell.envs);
}

static void	init_minishell(char **envp)
{
	g_minishell.envs = tab_to_list(envp);
	g_minishell.signal = 0;
	g_minishell.exit_status = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc > 1)
		return (usage(argv[0]), 1);
	init_minishell(envp);
	execute_shell_commands();
	return (g_minishell.exit_status);
}


//TO DO
//Gerer les erreurs d executions
//Gerer les valeurs de retour
//Gerer les signaux
//Gerer les builtins
//Proteger les builtins

//COMMANDS
/*
"Coucou" -> commande sans executable, excve : Syscall param execve(filename) points to unaddressable byte(s)


*/