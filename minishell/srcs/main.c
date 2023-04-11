/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/11 18:09:24 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

int	executing(t_list *commands)
{
	int last_pid;

	last_pid = pipex(commands);

	//wait_pid
	while (wait(NULL) != -1)
		;
	//gestion des signaux et du status
	return (0);
}

char	*read_line(void)
{
	char	*line;

	line = readline("minisheesh> ");
	if (!line)
		return (NULL);
	//ADD_HISTORY 
	return (line);
}

//on va lire la ligne du prompte pour la parser et l'executer
void	routine(void)
{
	// t_list	*commands;
	// create_commands(&commands);
	char	*line;
	t_list	*commands;

	line = read_line();
	if (!line)
		return ;
	if (line)
	{
		// commands = parse_line(line);
		create_commands(&commands);
		if (commands)
			executing(commands);
		ft_lstclear(&commands, free_command);
	}
	free(line);
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
	(void)argv;
	(void)argc;

	init_minishell(envp);
	routine();

	return (0);
}
