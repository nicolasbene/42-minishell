/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/21 18:32:06 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nbr_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ifbuiltins(char **av)
{
	if (ft_strcmp(av[0], "echo") == 0)
		return (0);
	else
		return (2);
}

int	builtins_parent(int ac, char **av, int fd_io[2], int fd_in)
{
	if (fd_io[0] == -1 || fd_io[1] == -1)
		return (1);
	redirect_input_output(fd_io, fd_in);
	if (ft_strcmp(av[0], "echo") == 0)
		return (echo(ac, av));
	else
		return (2);
}

int	forks(t_list *commands, int fd_io[2], int fd_pipe[2])
{
	t_list		*tmp_commands;
	t_command	*cmd;
	char		*pathname;
	int			last_pid;

	tmp_commands = commands;
	last_pid = 0;
	//on parcours les commands
	while (tmp_commands)
	{
		cmd = tmp_commands->content;
		//avant l'execution dune commande on gere les rd et pipe	
		handle_redirects(fd_io, fd_pipe,
			tmp_commands->next != NULL, cmd);
		//on recupere le path d'execution
		pathname = file_to_execute(cmd->args[0]);
		//on recupere le pid du child qui vient detre execute
		last_pid = execute_command(commands, pathname, cmd->args,
				fd_io, fd_pipe[0]);
		free(pathname);
		tmp_commands = tmp_commands->next;
	}
	return (last_pid);
}

//on gere si on a besoin d'un fork ou non
int	pipex(t_list *commands)
{
	t_command	*cmd;
	int			last_pid;
	int			fd_pipe[2];
	int			fd_io[2];

	last_pid = 0;
	//on duplique l'entree std sur la tete de lecture
	fd_pipe[0] = dup(STDIN_FILENO);
	fd_pipe[1] = -1;
	cmd = commands->content;
	//si y a une seule commande et que c un builtin on execute dans le parent
	if (cmd->args && commands->next == NULL && ifbuiltins(cmd->args) == 0)
	{
		handle_redirects(fd_io, fd_pipe, commands->next != NULL, cmd);
		builtins_parent(nbr_args(cmd->args), cmd->args, fd_io, fd_pipe[0]);
	}
	else
		//sinon on fork pour execve et on recup le pid du dernier enfant execute
		last_pid = forks(commands, fd_io, fd_pipe);
	return (last_pid);
}
