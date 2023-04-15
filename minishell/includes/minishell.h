/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:17:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/15 16:27:20 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"


# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <sys/wait.h>

# include <signal.h>

typedef struct s_minishell
{
	t_list	*envs;
	int		signal;
	int		exit_status;
}				t_minishell;

typedef struct s_env
{
	char	*name;
	char	*value;
}				t_env;

typedef enum e_redirect_type
{
	RD_IN = 1,
	RD_OUT = 2,
	RD_APPEND = 4,
	RD_HEREDOC = 8,
}			t_redirect_type;

typedef struct s_redirect
{
	int				fd;
	char			*file;
	t_redirect_type	type;
}				t_redirect;

//voir pour integrer fd_rw[2] dans la struct command
typedef struct s_command
{
	char	**args;
	t_list	*redirects;
}				t_command;

//pipex.c
int		pipex(t_list *commands);

//execute_command.c
void	piping(int fd[2], int fd_in);
int		execute_command(t_list *commands, char *pathname, char **args, int fd_rw[2], int fdin);

//redir.c
int		redir_input(int fdin, t_list *commands);
int		redir_output(int fdout, t_list *commands);

//get_path.c
char	*get_cmd(char **cmd_paths, char **cmd_tab);
char	*find_path(char **envp);
char	*file_to_execute(char *cmd);

//create-command.c
void	create_commands(t_list **commands);

//free_command.c
void	free_commands(t_list *commands);
void	ft_free_tab(char **tab);


//env.c
void	free_env(void *content);
t_list	*tab_to_list(char **envp);

//list_to_tab.c
char	**list_to_tab(t_list *lst);

//execution.c
int		executing(t_list *commands);

//print_error.c
void	print_error(char *format, char *arg1, char *arg2);

//process_rd.c
int		open_fd(t_redirect_type type, char *file);


#endif