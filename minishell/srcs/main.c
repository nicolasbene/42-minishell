/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:11:51 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/04 18:44:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_string_array(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_redirect(void *content)
{
	t_redirect *redirect;

	if (!content)
		return ;
	redirect = (t_redirect *)content;
	free(redirect->file);
	free(redirect);
}

void	free_command(void *content)
{
	t_command *cmd;

	if (!content)
		return ;
	cmd = (t_command *)content;
	ft_lstclear(&cmd->redirects, free_redirect);
	ft_free_string_array(cmd->args);
	free(cmd);
}

void	free_commands(t_list **commands)
{
	if (!commands || !*commands)
		return ;
	ft_lstclear(commands, free_command);
}

void create_commands(t_list **commands)
{
    // Création du premier élément
    t_command *cmd1 = malloc(sizeof(t_command));
    cmd1->args = malloc(sizeof(char*) * 3);
    cmd1->args[0] = ft_strdup("ls");
    cmd1->args[1] = ft_strdup("-l");
    cmd1->args[2] = NULL;
    cmd1->redirects = NULL; // pas de redirections pour ce premier élément
	cmd1->fd_io[0] = -1;
    cmd1->fd_io[1] = -1;
    t_list *elem1 = malloc(sizeof(t_list));
    elem1->content = cmd1;
    elem1->next = NULL;

    // // Création du deuxième élément
    t_command *cmd2 = malloc(sizeof(t_command));
    cmd2->args = malloc(sizeof(char*) * 4);
    cmd2->args[0] = ft_strdup("wc");
    cmd2->args[1] = ft_strdup("-l");
	cmd2->args[2] = ft_strdup("cat");
	cmd2->args[3] = NULL;
    t_redirect *redir = malloc(sizeof(t_redirect));
    redir->file = ft_strdup("file1");
    redir->fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    redir->type = RD_OUT;
	cmd2->redirects = malloc(sizeof(t_list));
    cmd2->redirects->content = redir;
    cmd2->redirects->next = NULL;
    cmd2->fd_io[0] = -1;
    cmd2->fd_io[1] = -1;
    t_list *elem2 = malloc(sizeof(t_list));
    elem2->content = cmd2;
    elem2->next = NULL;

	// // Création du troisieme élément
    // t_command *cmd3 = malloc(sizeof(t_command));
    // cmd3->args = malloc(sizeof(char*) * 2);
    // cmd3->args[0] = ft_strdup("ls");
    // cmd3->args[1] = NULL;
    // cmd3->redirects = NULL;
    // // t_redirect *redir2 = malloc(sizeof(t_redirect));
    // // redir2->file = ft_strdup("output2.txt");
    // // redir2->fd = open(redir2->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // // redir2->type = RD_OUT;
    // // cmd3->redirects->content = redir2;
    // // cmd3->redirects->next = NULL;
    // cmd3->fd_rw[0] = -1;
    // cmd3->fd_rw[1] = -1;
    // t_list *elem3 = malloc(sizeof(t_list));
    // elem3->content = cmd3;
    // elem3->next = NULL;

    // Ajout des deux éléments à la liste chaînée
    *commands = elem1;
    elem1->next = elem2;
	elem2->next = NULL;
}

int	executing(t_list *commands, char **envp)
{
	int last_pid;

	last_pid = pipex(commands, envp);

	//wait_pid
	while (wait(NULL) != -1)
		;
	//gestion des signaux et du status
	return (0);
}

//on va lire la ligne du prompte pour la parser et l'executer
void	routine(char **envp)
{
	t_list *commands;
	
	commands = malloc(sizeof(t_list));
	create_commands(&commands);
		if (commands)
			executing(commands, envp);
	free_commands(&commands);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	(void)argc;
	
	// init_minishell(envp);
	routine(envp);

	return (0);
}
