/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:17:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/09 14:17:55 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include "minishell_includes.h"
# include "minishell_parser.h"

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
t_env	*add_env_back(t_env *env, t_env *node_env);

//list_to_tab.c
char	**list_to_tab(t_env *lst);

//execution.c
int		executing(t_cmd *commands);

//print_error.c
void	print_error(const char *format, const char *arg1, const char *arg2);

//open_fd.c
int		open_fd(t_rdtype type, char *file);

//builtins
	//echo
int		echo(int ac, char **av);
	//unset
int		ft_unset(char **args);
int		ft_intoenv(char *tofind);
void	unset_var(int index);
	//cd
int		ft_cd(char **args);
int		ft_path(char **args);
int		ft_set_directory(char *path, int ishome);
int		ft_switchpwd(char *path, int ishome);
char	*ft_joinhomepath(char *path);
int		ft_switchenvcont(char *new_content, int index);
int		ft_setenv(char *env_name, char *new_content);
t_env	*ft_add_env(char *env_name, char *new_content);
char	*ft_getenv(char *str);
	//exit
void	ft_init_exit(char **args, t_cmd *cmd, int i);
void	ft_exit(t_cmd *cmd, int i);
void	ft_parsing_exitarg(char *arg, t_cmd *cmd);
void	ft_error_numeric(char *arg, t_cmd *cmd);
long long	ft_atoi_exit(const char *str, int i, int *toolongnb);
int		ft_isspace(char c);
	//pwd
int		ft_pwd(void);

//pipex->built-in
int		builtins(int ac, t_cmd *cmd);
int		builtins_parent(int ac, t_cmd *cmd, int fd_io[2], int fd_in); // ici t_cmd 










// ///////////////////////////////////////////////////////////////////////
// //PARTIE NWYSEUR

// //TOKEN.H

// enum	e_type
// {
// 	TOKEN_WORD,
// 	TOKEN_PIPE,
// 	TOKEN_G,
// 	TOKEN_GG,
// 	TOKEN_L,
// 	TOKEN_LL,
// 	TOKEN_LQ,
// 	TOKEN_LQQ,
// 	TOKEN_EOF,
// };

// typedef struct mst_struct
// {
// 	char				*value;
// 	enum e_type			type;
// 	struct mst_struct	*next;
// }	t_mst;

// // Token
// t_mst		*ft_init_token(char *value, int type);
// void		ft_mslstokenclear(t_mst **lst);
// void		ft_mslstokenadd_back(t_mst **lst, t_mst *new);
// t_mst		*ft_msltokenlast(t_mst *lst);
// int			ft_mslstokensize(t_mst *lst);

// ////////////////////////
// //LEXER.H


// typedef struct lexer_struct
// {
// 	char	*str;
// 	size_t	str_size;
// 	char	c;
// 	int		i;
// }	t_mslex;

// // lexer
// t_mslex	*ft_init_lexer(char *str);
// void	ft_lexer_advance(t_mslex *mslex);
// t_mst	*ft_lexer_adv_ret(t_mslex *mslex, t_mst *mst);
// char	ft_lexer_peek(t_mslex *mslex, int offset);
// void	ft_lexer_skip_blank(t_mslex *mslex);
// t_mst	*ft_lexer_next_token(t_mslex *mslex);
// t_mst	*ft_lexer_parse_word(t_mslex *mslex);
// char	*ft_lexer_parse_quote(t_mslex *mslex, char *value, int c);
// t_mst	*ft_lexer_main(char *str);

// /* Utils */

// char	*ft_strjoinchara(char *s1, char c);
// int		ft_ischara(char c);
// int		ft_strchrms(char *str, int c);


// ///////////////////
// //PARSER.H
// // enum	e_rdtype
// // {
// // 	RD_INF = 4,
// // 	RD_OUT = 2,
// // 	RD_APP = 3,
// // 	RD_HERE = 5,
// // };

// typedef enum e_errtype
// {
// 	NO_ERR,
// 	SYNTAX_ERR,
// 	PIPE_ERR,
// 	RD_ERR,
// }	t_err;

// // Parser
// // Syntax Checker
// t_cmd		*ft_main_parser(t_mst *mst);
// int			ft_syntax_check(t_mst *mst);
// int			ft_printerr(t_mst *tmp, int err);
// int			ft_check_rd(t_mst *tmp);
// int			ft_check_pipe(t_mst *tmp, t_mst *prev);

// // Cmd List Creator
// // t_cmd		*ft_parser_struct(t_mst *mst);
// t_cmd		*ft_parser_struct(t_mst *mst);
// t_cmd		*ft_cmd_maillon(t_mst **mst, int *nb);
// void		ft_cmdlstokenadd_back(t_cmd **lst, t_cmd *new);
// void		ft_rdlstokenadd_back(t_rdlist **lst, t_rdlist *new);
// t_rdlist	*ft_init_rdlist(t_mst *mst, int *nb);
// t_cmd		*ft_init_cmd(int *nb);
// void		ft_cmd_size(t_mst *mst, int *nb);

// // Parser Free
// void		ft_free_cmd(t_cmd **lst);
// void		ft_rdlstclear(t_rdlist **lst);
// void		ft_free_list(t_cmd **cmd, t_mst **mst);
// void		ft_freedbltab(char **tab);

//
#endif