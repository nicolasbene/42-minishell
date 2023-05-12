/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:21:55 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/12 19:51:26 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

char	*ft_joinhomepath(char *path)
{
	char		*tmp;
	char		*tmppath;

	if (!ft_strncmp(path, "~/", 2))
	{
		tmp = ft_getenv("HOME");
		if (tmp)
		{
			tmppath = ft_substr(path, 1, ft_strlen(path));
			free(path);
			path = ft_strjoin(tmp, tmppath);
			free(tmppath);
			free(tmp);
			return (path);
		}
	}
	return (path);
}

int	ft_switchpwd(char *path, int ishome)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (chdir(path) == 0)
	{
		if (pwd)
		{
			ft_setenv("OLDPWD", pwd);
			free(pwd);
		}
		pwd = getcwd(NULL, 0);
		if (pwd)
		{
			ft_setenv("PWD", pwd);
			free(pwd);
		}
		if (ishome)
			free(path);
		return (1);
	}
	free(pwd);
	return (0);
}

int	ft_set_directory(char *path, int ishome)
{
	struct stat	statstruct;

	if (ft_switchpwd(path, ishome))
		return (1);
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	g_minishell.exit_status = 1;
	if (stat(path, &statstruct) == -1)
	{
		ft_putstr_fd(": No such file or directory", 2);
		g_minishell.exit_status = 127;
	}
	else if (!(statstruct.st_mode & S_IXUSR))
		ft_putstr_fd(": Permission denied", 2);
	else
		ft_putstr_fd(": Not a directory", 2);
	ft_putchar_fd('\n', 2);
	if (ishome)
		free(path);
	return (1);
}

int	ft_path(char **args)
{
	char	*tmp;

	if (ft_strcmp(args[1], "-") == 0)
	{
		tmp = ft_getenv("OLDPWD");
		if (tmp)
		{
			ft_set_directory(tmp, 0);
			free(tmp);
		}
		tmp = ft_getenv("PWD");
		if (tmp)
		{
			ft_putstr_fd(tmp, 1);
			free(tmp);
			ft_putchar_fd('\n', 1);
		}
		return (1);
	}
	return (ft_set_directory(args[1], 0));
}

int	ft_cd(char **args)
{
	char	*home;

	g_minishell.exit_status = 0;
	home = NULL;
	if (args && args[1] && args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_minishell.exit_status = 1;
		return (1);
	}
	if (!args[1] || ft_strcmp(args[1], "~") == 0
		|| ft_strcmp(args[1], "--") == 0)
	{
		home = ft_getenv("HOME");
		if (!home)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			g_minishell.exit_status = 1;
			return (1);
		}
		return (ft_set_directory(home, 1));
	}
	args[1] = ft_joinhomepath(args[1]);
	return (ft_path(args));
}
