/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:50:35 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 18:51:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

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
