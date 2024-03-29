/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:35:07 by nwyseur           #+#    #+#             */
/*   Updated: 2023/05/17 18:39:46 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

extern t_minishell	g_minishell;

int	ft_check_pipe(t_mst *tmp, t_mst *prev)
{
	if (tmp->type == TOKEN_PP)
		return (PIPE_ERR);
	else if (prev == NULL || prev->type == TOKEN_L || prev->type == TOKEN_G
		|| prev->type == TOKEN_LL || prev->type == TOKEN_GG)
		return (PIPE_ERR);
	else if (tmp->next == NULL || tmp->next->type == TOKEN_PIPE
		|| tmp->next->type == TOKEN_EOF)
		return (PIPE_ERR);
	else
		return (NO_ERR);
}

int	ft_check_rd(t_mst *tmp)
{
	if (tmp->next->type != TOKEN_WORD)
		return (RD_ERR);
	else
		return (NO_ERR);
}

int	ft_printerr(t_mst *tmp, int err)
{
	if (err == PIPE_ERR)
		ft_printf_fd(2, "syntax error near unexpected token `%s'\n", tmp->value);
	else if ((err == RD_ERR && tmp->next->value == NULL)
		|| (err == RD_ERR && (tmp->next->type == TOKEN_L
				|| tmp->next->type == TOKEN_G)))
		ft_printf_fd(2, "syntax error near unexpected token `newline'\n");
	else if (err == RD_ERR && tmp->next->value)
		ft_printf_fd(2, "syntax error near unexpected token `%s'\n",
			tmp->next->value);
	return (err);
}

int	ft_syntax_check(t_mst *mst)
{
	t_mst	*tmp;
	t_mst	*prev;
	int		err;

	tmp = mst;
	err = 0;
	prev = NULL;
	while (tmp != NULL && err == 0)
	{
		if (tmp->type == TOKEN_PIPE || tmp->type == TOKEN_PP)
			err = ft_check_pipe(tmp, prev);
		else if (tmp->type == TOKEN_LQ || tmp->type == TOKEN_LQQ)
			err = SYNTAX_ERR;
		else if (tmp->type == TOKEN_L || tmp->type == TOKEN_G
			|| tmp->type == TOKEN_LL || tmp->type == TOKEN_GG)
			err = ft_check_rd(tmp);
		if (err != 0)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (err != 0)
		return (ft_printerr(tmp, err));
	return (err);
}

t_cmd	*ft_main_parser(t_mst *mst)
{
	t_cmd	*cmd;

	if (ft_syntax_check(mst) != 0)
	{
		ft_mslstokenclear(&mst);
		g_minishell.exit_status = 2;
		return (NULL);
	}
	else
	{
		cmd = ft_parser_struct(mst);
		if (cmd == NULL)
			return (NULL);
	}
	g_minishell.commands = cmd;
	return (cmd);
}
