/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:28:13 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/05 11:38:43 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

void	ft_cmd_size(t_mst *mst, int *nb)
{
	t_mst	*tmp;

	nb[0] = 0;
	nb[1] = 0;
	tmp = mst;
	while (tmp != NULL && tmp->type != TOKEN_PIPE)
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
			return (free(new), NULL);
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

t_cmd	*ft_cmd_maillon(t_mst **mst, int *nb)
{
	t_cmd		*link;
	t_rdlist	*new;
	int			i;

	i = 0;
	link = ft_init_cmd(nb);
	if (link == NULL)
		return (NULL);
	while ((*mst) != NULL && (*mst)->type != TOKEN_PIPE)
	{
		if ((*mst)->type >= TOKEN_G && (*mst)->type <= TOKEN_LL)
		{
			new = ft_init_rdlist((*mst), nb);
			if (new == NULL)
				return (ft_free_cmd(&link), NULL);
			ft_rdlstokenadd_back(&link->rd, new);
			(*mst) = (*mst)->next->next;
		}
		else
		{
			link->arg[i++] = (*mst)->value;
			(*mst) = (*mst)->next;
		}
	}
	return (link);
}

t_cmd	*ft_parser_struct(t_mst *mst)
{
	t_cmd	*cmd;
	t_cmd	*new;
	t_mst	*tmp;
	int		nb[2];

	tmp = mst;
	cmd = NULL;
	new = NULL;
	while (tmp != NULL)
	{
		ft_cmd_size(tmp, nb);
		new = ft_cmd_maillon(&tmp, nb);
		if (new == NULL)
			return (ft_free_list(&cmd, &mst), NULL);
		ft_cmdlstokenadd_back(&cmd, new);
		if (tmp != NULL)
			tmp = tmp->next;
	}
	return (cmd);
}

// checker si cmdmaillon return NULL qu est-ce qu on fait? 
//est-ce qu on return une erreurt ou est-ce qu'on considere que le mqillon 
//ajoute est null? pareil poiur la chaine de redirection 