/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:43:07 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/16 15:41:29 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_includes.h"

void	print_error(const char *format, const char *arg1, const char *arg2)
{
	int	save;

	save = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("minishell: ");
	if (arg2)
		printf(format, arg1, arg2);
	else if (arg1)
		printf(format, arg1);
	else
		printf("%s", format);
	printf("\n");
	dup2(save, STDOUT_FILENO);
	close(save);
}
