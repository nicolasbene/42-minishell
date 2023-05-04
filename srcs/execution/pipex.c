/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:35:37 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/04 18:11:33 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

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
	if (ft_strcmp(av[0], "unset") == 0)
		return (0);
	if (ft_strcmp(av[0], "cd") == 0)
		return (0);
	else
		return (2);
}

int	builtins(int ac, char **av)
{
	if (ft_strcmp(av[0], "echo") == 0)
		return (echo(ac, av));
	if (ft_strcmp(av[0], "unset") == 0)
		return (ft_unset(av));
	if (ft_strcmp(av[0], "cd") == 0)
		return (ft_cd(av));
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
	if (ft_strcmp(av[0], "unset") == 0)
		return (ft_unset(av));
	if (ft_strcmp(av[0], "cd") == 0)
		return (ft_cd(av));
	else
		return (2);
}

int	forks(t_cmd *commands, int fd_io[2], int fd_pipe[2])
{
	t_cmd		*tmp_commands;
	char		*pathname;
	int			last_pid;

	last_pid = 0;
	tmp_commands = commands;
	//on parcours les commands
	while (tmp_commands)
	{
		//avant l'execution dune commande on gere les rd et pipe	
		handle_redirects(fd_io, fd_pipe,
			tmp_commands->next != NULL, tmp_commands);
		ft_variable_exp(tmp_commands, g_minishell.envs);
		//on recupere le path d'execution
		pathname = file_to_execute(tmp_commands->arg[0]);
		//on recupere le pid du child qui vient detre execute
		last_pid = execute_command(tmp_commands, pathname, tmp_commands->arg,
				fd_io, fd_pipe[0]);
		free(pathname);
		tmp_commands = tmp_commands->next;
	}
	return (last_pid);
}

//on gere si on a besoin d'un fork ou non
int	pipex(t_cmd *commands)
{
	int			last_pid;
	int			fd_pipe[2];
	int			fd_io[2];

	last_pid = 0;
	//on duplique l'entree std sur la tete de lecture
	fd_pipe[0] = dup(STDIN_FILENO);
	fd_pipe[1] = -1;
	//si y a une seule commande et que c un builtin on execute dans le parent
	if (commands->arg && commands->next == NULL && ifbuiltins(commands->arg) == 0)
	{
		ft_variable_exp(commands, g_minishell.envs);
		handle_redirects(fd_io, fd_pipe, commands->next != NULL, commands);
		builtins_parent(nbr_args(commands->arg), commands->arg, fd_io, fd_pipe[0]);
	}
	else
		//sinon on fork pour execve et on recup le pid du dernier enfant execute
		last_pid = forks(commands, fd_io, fd_pipe);
	return (last_pid);
}
