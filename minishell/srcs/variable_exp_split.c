/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_exp_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:28:23 by nwyseur           #+#    #+#             */
/*   Updated: 2023/04/14 15:09:22 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell_includes.h"

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

int	ms_split_i(t_cmd *cmd, char **new, int *k, int i)
{
	int	j;

	j = 0;
	while (cmd->arg[i][j] != '\0')
	{
		if (cmd->arg[i][j] == ' ')
			j++;
		if (cmd->arg[i][j] != '\0' && cmd->arg[i][j] != ' ')
		{
			new[(*k)] = ft_copyword(&cmd->arg[i][j],
					ft_wordlen(&cmd->arg[i][j]), new, (*k));
			if (new[(*k)] == NULL)
				return (0);
			(*k)++;
			j = j + ft_wordlen(&cmd->arg[i][j]);
		}
	}
	return (1);
}

char	**ms_split(t_cmd *cmd)
{
	char	**new;
	int		wc;
	int		i;
	int		k;

	wc = 0;
	i = -1;
	k = 0;
	ms_wordcount(cmd->arg, &wc);
	printf("[WORD COUNT] = %i\n", wc);
	new = (char **)malloc((wc + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (cmd->arg[++i] != NULL)
	{
		if (ms_split_i(cmd, new, &k, i) == 0)
			return (NULL);
	}
	new[wc] = NULL;
	ft_freedbltab(cmd->arg);
	return (new);
}
