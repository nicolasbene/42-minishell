/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:28:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/13 10:52:47 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

int	ms_passquote(char *arg, char c)
{
	int	i;

	i = 0;
	i++;
	while (arg[i] != c)
		i++;
	return (i);
}

int	ms_wordcount_i(char *arg, int *wc)
{
	int	k;

	k = 0;
	++(*wc);
	while (arg[k] != '\0' && arg[k] != ' ')
	{
		if (arg[k] == '\"' || arg[k] == '\'') // le faire avec ' et " k += fonction
			k += ms_passquote(&arg[k], arg[k]);
		else
			k++;
	}
	return (k);
}

void	ms_wordcount(char **arg, int *wc)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i] != NULL)
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			if (arg[i][j] == ' ')
				j++;
			if (arg[i][j] != '\0' && arg[i][j] != ' ')
				j += ms_wordcount_i(&arg[i][j], wc);
		}
	}
}

int	ft_wordlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != ' ')
	{
		if (s[i] == '\"' || s[i] == '\'')
			i += ms_passquote(&s[i], s[i]);
		else
			i++;
	}
	return (i);
}
////////////
void	ft_strfree(char **sstr, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
}

char	*ft_copyword(char const *s, int len, char **sstr, int j)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
	{
		ft_strfree(sstr, j);
		return (NULL);
	}
	while (s[i] != '\0' && i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
///////////

char	**ms_split(t_cmd *cmd)
{
	char	**new;
	int		wc;
	int		i;
	int		j;
	int		k;

	wc = 0;
	i = -1;
	k = 0;
	ms_wordcount(cmd->arg, &wc);
	printf("[WORD COUNT] = %i\n", wc);
	new = (char **)malloc((wc + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL) ; 
	while (cmd->arg[++i] != NULL)
	{
		j = 0;
		while (cmd->arg[i][j] != '\0')
		{
			if (cmd->arg[i][j] == ' ')
				j++;
			if (cmd->arg[i][j] != '\0' && cmd->arg[i][j] != ' ')
			{
				new[k] = ft_copyword(&cmd->arg[i][j], ft_wordlen(&cmd->arg[i][j]), new, k);
				if (new[k] == NULL)
						return (NULL) ;
				k++;
				j = j + ft_wordlen(&cmd->arg[i][j]);
			}
		}
	}
	ft_freedbltab(cmd->arg);
	return (new);
}

