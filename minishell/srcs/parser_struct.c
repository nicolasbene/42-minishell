/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:28:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/03 12:13:16 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_lexer.h"
#include "../includes/minishell_tokens.h"
#include "../includes/minishell_parser.h"

int	*ft_cmd_size(t_mst *mst)
{
	int		nb[2];
	t_mst	*tmp;

	nb[0] = 0;
	nb[1] = 0;
	tmp = mst;
	while (tmp != NULL || tmp->type != TOKEN_PIPE) // ou mettre topken EOF?
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
	return (nb);
}

t_cmd	*ft_init_cmd(t_mst *mst, int *nb)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(1 * sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	else
	{
		new->arg = (char **)malloc((nb[0] + 1) * sizeof(char *));
		new->rd = NULL;
	}
	new->next = NULL;
	return (new);
}

t_cmd	*ft_cmd_maillon(t_mst *mst, int *nb)
{
	t_cmd	*link;

	link = ft_init_cmd(mst, nb);
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
		nb = ft_cmd_size(tmp);

	}
}