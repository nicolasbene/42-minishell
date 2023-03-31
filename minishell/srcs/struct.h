/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:35:56 by nibenoit          #+#    #+#             */
/*   Updated: 2023/03/31 18:16:50 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "../libft/libft.h"

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

typedef struct s_command
{
	int		fd_rw[2];
	char	**args;
}				t_command;

#endif