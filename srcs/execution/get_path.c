/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:36:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/12 12:03:36 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

t_env	*get_env_el(char *av)
{
	t_env	*envs;

	envs = g_minishell.envs;
	while (envs != NULL)
	{
		if (ft_strncmp(av, envs->name, ft_strlen(envs->name)) == 0
			&& ft_strlen(av) == ft_strlen(envs->name))
			return (envs);
		envs = envs->next;
	}
	return (NULL);
}

static char	*concat_path_command(char *path, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
	}
	else
		cmd_path = ft_strjoin(path, cmd);
	return (cmd_path);
}

char	*get_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (path[i])
	{
		tmp = concat_path_command(path[i], cmd);
		if (!tmp)
			exit(12);
		if (access(tmp, F_OK) == 0)
		{
			if (cmd_path)
				free(cmd_path);
			cmd_path = tmp;
			if (access(cmd_path, X_OK) == 0)
				return (cmd_path);
		}
		else
			free(tmp);
		i++;
	}
	return (cmd_path);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}


char	*get_path_cmd(char *cmd)
{
	t_env	*env;
	char	**path;
	char	*cmd_path;

	env = get_env_el("PATH");
	if (!env || !env->content)
		return (NULL);
	path = ft_split(env->content, ':');
	if (!path)
		exit(12);
	cmd_path = get_path(path, cmd);
	free_path(path);
	if (cmd_path == NULL)
		return (NULL);
	return (cmd_path);
}

char	*file_to_execute(char *cmd)
{
	char	*tmp;

	if (ft_strncmp(cmd, "./", 2) == 0
		|| ft_strncmp(cmd, "../", 2) == 0
		|| ft_strncmp(cmd, "/", 1) == 0)
		tmp = ft_strdup(cmd);
	else if (ft_strcmp(cmd, "echo") == 0)
		tmp = ft_strdup("echo");
	else if (ft_strcmp(cmd, "env") == 0)
		tmp = ft_strdup("env");
	else if (ft_strcmp(cmd, "cd") == 0)
		tmp = ft_strdup("cd");
	else if (ft_strcmp(cmd, "export") == 0)
		tmp = ft_strdup("export");
	else if (ft_strcmp(cmd, "pwd") == 0)
		tmp = ft_strdup("pwd");
	else if (ft_strcmp(cmd, "unset") == 0)
		tmp = ft_strdup("unset");
	else if (ft_strcmp(cmd, "exit") == 0)
		tmp = ft_strdup("exit");
	else
		tmp = get_path_cmd(cmd);
	return (tmp);
}