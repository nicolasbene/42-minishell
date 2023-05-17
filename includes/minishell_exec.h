/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:17:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/17 18:55:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include "minishell_includes.h"

typedef struct s_minishell
{
	t_env	*envs;
	void	*commands;
	int		signal;
	int		exit_status;
}				t_minishell;

//pipex.c
int			nbr_args(char **av);
int			pipex(t_cmd *commands);

//execute_command.c
void		redirect_input_output(int fd[2], int fd_in);
int			execute_command(char **args, char *pathname,
				int fd_io[2], int fd_in);
void		exit_error(const char *format, const char *s,
				int code, char *pathname);

//handle_rd.c
int			handle_redirects(int fd_io[2], int fd_pipe[2],
				int next, t_cmd *cmd);
int			redir_input(t_cmd *cmd, int fd_in);
int			redir_output(t_cmd *cmd, int fd_out);

//get_path.c
char		*get_path(char **path, char *cmd);
t_env		*get_env_el(char *av);

//file_to_execute.c
char		*file_to_execute(char *cmd);

//free_command.c
void		free_commands(t_cmd *commands);
void		free_command(void *content);
void		free_tab(char **tab);
void		free_redirect(void *content);

// void	free_env(t_env *env);
void		free_envs(t_env *envs);
void		free_env(t_env *env);

//list_to_tab.c
char		**list_to_tab(t_env *lst);

//execution.c
int			executing(t_cmd *commands);

//print_error.c
void		print_error(const char *format, const char *arg1, const char *arg2);

//open_fd.c
int			open_fd(t_rdtype type, char *file);

//handle_builtins.c
int			builtins(int ac, char **args);
int			builtins_parent(int ac, char **args, int fd_io[2], int fd_in);
int			ifbuiltins(char **av);

//is_directory.c
bool		is_directory(const char *path);

//is_rdout.c
bool		is_rdout(t_rdtype type);

//close_save_std.c
void		close_save_std(void);

//heredoc.c
int			handle_heredoc(const char *stop);

//readinput.c
char		*readinput(const char *prompt);

//utils.c
bool		is_empty(const char *s);

//builtins
	//echo
int			ft_echo(int ac, char **av, int i);

	//unset
int			ft_unset(char **args);
int			ft_intoenv(char *tofind);
void		unset_var(int index);

	//cd
int			ft_cd(char **args);
int			ft_path(char **args);
int			ft_set_directory(char *path, int ishome);
int			ft_switchpwd(char *path, int ishome);
char		*ft_joinhomepath(char *path);
int			ft_switchenvcont(char *new_content, int index);
int			ft_setenv(char *env_name, char *new_content);
t_env		*ft_add_env(char *env_name, char *new_content);
char		*ft_getenv(char *str);

	//exit
void		ft_init_exit(char **args, t_cmd *cmd, int i);
void		ft_exit(t_cmd *cmd, int i);
void		ft_parsing_exitarg(char *arg, t_cmd *cmd);
void		ft_error_numeric(char *arg, t_cmd *cmd);
long long	ft_atoi_exit(const char *str, int i, int *toolongnb);
int			ft_isspace(char c);

	//pwd
int			ft_pwd(int ac, char **args);

	//env
t_env		*tab_to_list(char **envp);
t_env		*add_env_back(t_env *env, t_env *node_env);
int			ft_env(int ac, char **av);
t_env		*add_node_env(t_env *envs, char *av);

	//export
int			ft_export(int ac, char **av);
t_env		*add_empty_env(t_env *envs, char *s);
int			check_equal(char **av);

//signal.c
void		handle_signals(void);
void		handle_signals_exec(void);
void		handle_signals_heredoc(void);
void		reset_signals(void);

#endif