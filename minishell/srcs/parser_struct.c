/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:28:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/03 18:09:59 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"
#include "../includes/minishell_parser.h"

void	ft_cmd_size(t_mst *mst, int *nb)
{
	t_mst	*tmp;

	nb[0] = 0;
	nb[1] = 0;
	tmp = mst;
	while (tmp != NULL && tmp->type != TOKEN_PIPE) // ou mettre topken EOF?
	{
		if (tmp->type == TOKEN_G || tmp->type == TOKEN_GG
			|| tmp->type == TOKEN_L || tmp->type == TOKEN_LL)
		{
			nb[1]++;
			tmp = tmp->next->next;
		}
		else
		{
			nb[0]++;
			tmp = tmp->next;
		}
	}
}

t_cmd	*ft_init_cmd(int *nb)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(1 * sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	else
	{
		new->arg = (char **)malloc((nb[0] + 1) * sizeof(char *));
		if (new->arg == NULL)
			return (NULL);
		new->arg[nb[0]] = NULL;
		new->rd = NULL;
	}
	new->next = NULL;
	return (new);
}



t_rdlist	*ft_init_rdlist(t_mst *mst, int *nb)
{
	t_rdlist	*new;

	new = (t_rdlist *)malloc((nb[1] + 1) * sizeof(t_rdlist));
	if (new == NULL)
		return (NULL);
	else
	{
		new->str = mst->next->value;
		new->type = (enum e_rdtype)((int)mst->type);
	}
	new->next = NULL;
	return (new);
}

void	ft_rdlstokenadd_back(t_rdlist **lst, t_rdlist *new)
{
	t_rdlist	*tmp;

	if (lst && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (lst && *lst == NULL)
		*lst = new;
}

void	ft_cmdlstokenadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (lst && *lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (lst && *lst == NULL)
		*lst = new;
}

t_cmd	*ft_cmd_maillon(t_mst **mst, int *nb)
{
	t_cmd	*link;
	int		i;

	i = 0;
	link = ft_init_cmd(nb);
	while ((*mst) != NULL && (*mst)->type != TOKEN_PIPE) // ou mettre topken EOF?
	{
		if ((*mst)->type == TOKEN_G || (*mst)->type == TOKEN_GG
			|| (*mst)->type == TOKEN_L || (*mst)->type == TOKEN_LL)
		{
			ft_rdlstokenadd_back(&link->rd, ft_init_rdlist((*mst), nb));
			(*mst) = (*mst)->next->next;
		}
		else
		{
			link->arg[i] = (*mst)->value;
			i++;
			(*mst) = (*mst)->next;
		}
	}
	return (link);
}

t_cmd	*ft_parser_struct(t_mst *mst)
{
	t_cmd	*cmd;
	t_mst	*tmp;
	int		nb[2];

	tmp = mst;
	cmd = NULL;
	while (tmp != NULL)
	{
		ft_cmd_size(tmp, nb);
		ft_cmdlstokenadd_back(&cmd, ft_cmd_maillon(&tmp, nb));
		if (tmp != NULL)
			tmp = tmp->next;
	}
	return (cmd);
}
