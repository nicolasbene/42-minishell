/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:17:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/28 12:21:41 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include "minishell_includes.h"

typedef struct s_minishell
{
	t_env	*envs;
	int		signal;
	int		exit_status;
}				t_minishell;

//pipex.c
int		nbr_args(char **av);
int		pipex(t_cmd *commands);

//execute_command.c
void	redirect_input_output(int fd[2], int fd_in);
int		execute_command(t_cmd *commands, char *pathname, char **args, int fd_io[2], int fd_in);

//handle_rd.c
int		handle_redirects(int fd_io[2], int fd_pipe[2], int next, t_cmd *cmd);
int		redir_input(t_cmd *cmd, int fd_in);
int		redir_output(t_cmd *cmd, int fd_out);

//get_path.c
char	*get_cmd(char **cmd_paths, char **cmd_tab);
char	*find_path(char **envp);
char	*file_to_execute(char *cmd);

//create-command.c
// void	create_commands(t_list **commands);

//free_command.c
void	free_commands(t_cmd *commands);
void	free_command(void *content);
void	ft_free_tab(char **tab);
void	free_redirect(void *content);

//env.c
void	free_env(t_env *env);
void	free_envs(t_env **envs);
t_env	*tab_to_list(char **envp);

//list_to_tab.c
char	**list_to_tab(t_env *lst);

//execution.c
int		executing(t_cmd *commands);

//print_error.c
void	print_error(const char *format, const char *arg1, const char *arg2);

//open_fd.c
int		open_fd(t_rdtype type, char *file);

//builtins
int		echo(int ac, char **av);

//pipex->built-in
int		builtins(int ac, char **av);

//is_directory.c
bool	is_directory(const char *path);

//is_rdout.c
bool	is_rdout(t_rdtype type);

#endif