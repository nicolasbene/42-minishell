/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:47:10 by nicolasbeno       #+#    #+#             */
/*   Updated: 2023/04/26 15:23:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

// void	create_commands(t_list **commands)
// {
	
//     // Création du premier élément
//     t_command *cmd1 = malloc(sizeof(t_command));
//     cmd1->args = malloc(sizeof(char*) * 2);
//     cmd1->args[0] = ft_strdup("pwd");
//     // cmd1->args[1] = ft_strdup("-l");
//     cmd1->args[1] = NULL;
//     cmd1->redirects = NULL; // pas de redirections pour ce premier élément
//     t_list *elem1 = malloc(sizeof(t_list));
//     elem1->content = cmd1;
//     elem1->next = NULL;

//     // // Création du deuxième élément
//     t_command *cmd2 = malloc(sizeof(t_command));
//     cmd2->args = malloc(sizeof(char*) * 2);
//     cmd2->args[0] = ft_strdup("wc");
//     cmd2->args[1] = NULL;
// 	// cmd2->args[2] = ft_strdup("ok");
// 	// cmd2->args[3] = NULL;
//     t_redirect *redir = malloc(sizeof(t_redirect));
//     redir->file = ft_strdup("file10");
//     // redir->fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     redir->type = RD_OUT;
// 	cmd2->redirects = malloc(sizeof(t_list));
//     cmd2->redirects->content = redir;
//     cmd2->redirects->next = NULL;
//     t_list *elem2 = malloc(sizeof(t_list));
//     elem2->content = cmd2;
//     elem2->next = NULL;

// 	// // Création du troisieme élément
//     // t_command *cmd3 = malloc(sizeof(t_command));
//     // cmd3->args = malloc(sizeof(char*) * 2);
//     // cmd3->args[0] = ft_strdup("ls");
//     // cmd3->args[1] = NULL;
//     // cmd3->redirects = NULL;
//     // // t_redirect *redir2 = malloc(sizeof(t_redirect));
//     // // redir2->file = ft_strdup("output2.txt");
//     // // redir2->fd = open(redir2->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     // // redir2->type = RD_OUT;
//     // // cmd3->redirects->content = redir2;
//     // // cmd3->redirects->next = NULL;
//     // cmd3->fd_rw[0] = -1;
//     // cmd3->fd_rw[1] = -1;
//     // t_list *elem3 = malloc(sizeof(t_list));
//     // elem3->content = cmd3;
//     // elem3->next = NULL;

//     // Ajout des deux éléments à la liste chaînée
//     *commands = elem1;
//     elem1->next = elem2;
// 	elem2->next = NULL;
// }