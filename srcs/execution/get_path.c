/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:36:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 18:50:23 by nibenoit         ###   ########.fr       */
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
