/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:36:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/15 19:24:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	g_minishell;

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **cmd_paths, char **cmd_tab)
{
	char	*tmp;
	char	*command;

	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		command = ft_strjoin(tmp, cmd_tab[0]);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_paths++;
	}
	return (NULL);
}

char	*file_to_execute(char *cmd)
{
	char	*pathname;
	char	*env_path;
	char	**cmd_paths;
	char	**cmd_tab;
	char	**env_tab;

	cmd_tab = ft_split(cmd, ' ');
	ft_strchr(cmd_tab[0], '/');
	env_tab = list_to_tab(g_minishell.envs);
	env_path = find_path(env_tab);
	cmd_paths = ft_split(env_path, ':');
	pathname = get_cmd(cmd_paths, cmd_tab);
	ft_free_tab(cmd_paths);
	ft_free_tab(cmd_tab);
	ft_free_tab(env_tab);
	return (pathname);
}
