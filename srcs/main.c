/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/12 15:34:40 by nibenoit         ###   ########.fr       */
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

	line = readinput("minishell$ ");
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
		if (!is_empty(line))
		{
			mst = ft_lexer_main(line);
			commands = ft_main_parser(mst);
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
	if (envp && envp[0] && !g_minishell.envs)
		exit(12);
	g_minishell.signal = 0;
	g_minishell.exit_status = 0;
	g_minishell.commands = NULL;
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
//Gerer le echo $? -> aller chercher dans g_minishell.exit_status
//Gerer les signaux
//Gerer les builtins export
//Proteger les builtins

//COMMANDS
/*
$echo '''
$exit
--> leaks
*/