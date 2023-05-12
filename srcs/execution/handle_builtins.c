/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:17:28 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/12 17:30:20 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	ifbuiltins(char **av)
{
	if (ft_strcmp(av[0], "echo") == 0)
		return (0);
	if (ft_strcmp(av[0], "unset") == 0)
		return (0);
	if (ft_strcmp(av[0], "cd") == 0)
		return (0);
	if (ft_strcmp(av[0], "exit") == 0)
		return (0);
	if (ft_strcmp(av[0], "pwd") == 0)
		return (0);
	if (ft_strcmp(av[0], "env") == 0)
		return (0);
	if (ft_strcmp(av[0], "export") == 0)
		return (0);
	else
		return (2);
}

int	builtins(int ac, char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(ac, args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	if (ft_strcmp(args[0], "exit") == 0)
	{
		ft_init_exit(args, g_minishell.commands, 1);
		return (1);
	}
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(ac, args));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(ac, args));
	else
		return (2);
}

int	builtins_parent(int ac, char **args, int fd_io[2], int fd_in)
{
	if (fd_io[0] == -1 || fd_io[1] == -1)
		return (1);
	redirect_input_output(fd_io, fd_in);
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(ac, args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	if (ft_strcmp(args[0], "exit") == 0)
	{
		ft_init_exit(args, g_minishell.commands, 1);
		return (1);
	}
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(ac, args));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(ac, args));
	else
		return (2);
}
