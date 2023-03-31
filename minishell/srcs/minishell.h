/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:17:42 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/31 15:57:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include "builtin.h"
# include "struct.h"

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int	echo(int ac, char **av);

#endif