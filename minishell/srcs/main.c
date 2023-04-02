/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/31 16:52:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


typedef struct s_command
{
	int		fd_rw[2];
	char	**args;
}				t_command;

void create_commands(t_list *commands)
{
		t_command *cmd1 = malloc(sizeof(t_command));
		cmd1->args = malloc(3 * sizeof(char *));
		cmd1->args[0] = "echo";
		cmd1->args[1] = "koikoube";
		cmd1->args[2] = NULL;
		commands->content = cmd1;

		// t_command *cmd2 = malloc(sizeof(t_command));
		// cmd2->args = malloc(3 * sizeof(char *));
		// cmd2->args[0] = "cat";
		// cmd2->args[1] = "file1";
		// cmd2->args[2] = NULL;
		// commands->next = malloc(sizeof(t_list));
		// commands->next->content = cmd2;
		commands->next->next = NULL;
}
int	nbr_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	exec(char **args, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execve(args[0], args, envp);
	}
	return (pid);
}

int	forks(t_list *commands, char **envp)
{
	t_command	*cmd;
	int			last_pid;
	char		*tmp;
	
	while (commands)
	{
		cmd = commands->content;
		//redirection potentielles
		// tmp = get_path_cmd(cmd);

		last_pid = exec(cmd->args, envp);

		commands = commands->next;
	}
	return (last_pid);
}


int	pipex(t_list *commands, char **envp)
{
	int			last_pid;

	// if (cmd->args && command->next == NULL && ifbuiltins(cmd->args) == 0)
	// {
	// 	//redirections potentielles + builtin_parent
	// }
	// else
	last_pid = forks(commands, envp);
	
	return (0);
}


int	executing(t_list *commands, char **envp)
{
	pipex(commands, envp);
	return (0);
}

void	routine(char **envp)
{
	t_list *commands;
	
	create_commands(commands);
	while (1)
	{
		if (commands)
			executing(commands, envp);
	}
}


int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	(void)argc;
	
	routine(envp);

	return (0);
}