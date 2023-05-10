/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rdout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:17:01 by nibenoit          #+#    #+#             */
/*   Updated: 2023/04/28 12:17:18 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

bool	is_rdout(t_rdtype type)
{
	if (type == RD_OUT)
		return (true);
	if (type == RD_APP)
		return (true);
	return (false);
}
