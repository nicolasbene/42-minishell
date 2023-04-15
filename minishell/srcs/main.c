/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/15 19:16:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

void	usage(char *prog_name)
{
	print_error("%s: too many arguments", prog_name, NULL);
}

char	*read_line(void)
{
	char	*line;

	line = readline("minisheesh> ");
	if (!line)
		return (NULL);
	else if (*line)
		add_history(line);
	return (line);
}

void	execute_shell_commands(void)
{
	char	*line;
	t_list	*commands;

	while (1)
	{
		line = read_line();
		if (!line)
			break ;
		if (line)
		{
			// commands = parse_line(line);
			create_commands(&commands);
			if (commands)
				executing(commands);
			free_commands(commands);
		}
		free(line);
	}
	ft_lstclear(&g_minishell.envs, free_env);
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
