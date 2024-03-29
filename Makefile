# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 21:18:35 by nwyseur           #+#    #+#              #
#    Updated: 2023/05/19 13:19:41 by nibenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS_FILES	= main.c \
				readinput.c \
				print_error.c \
				signal.c \
				signal2.c \
				execution/pipex.c \
				execution/execute_command.c \
				execution/get_path.c \
				execution/file_to_execute.c \
				execution/handle_redirects.c \
				execution/free_command.c \
				execution/list_to_tab.c \
				execution/execution.c \
				execution/handle_open_fd.c \
				execution/is_directory.c \
				execution/is_rdout.c \
				execution/handle_builtins.c \
				execution/close_save_std.c \
				execution/heredoc.c \
				execution/utils.c \
				execution/free_envs.c \
				execution/tab_to_list.c \
				parser/lexer_main.c \
				parser/lexer_mvt.c \
				parser/lexer_utils.c \
				parser/parser_free_error.c \
				parser/parser_main.c \
				parser/parser_struct_2.c \
				parser/parser_struct.c \
				parser/token_management.c \
				parser/variable_exp_main.c \
				parser/variable_exp_utils.c \
				parser/variable_exp_utils_2.c \
				parser/variable_exp_utils_3.c \
				parser/variable_exp_split.c \
				parser/variable_exp_split_utils.c \
				parser/quote_management.c \
				parser/quote_management_utils.c \
				builtins/env.c \
				builtins/add_node_env.c \
				builtins/echo.c \
				builtins/unset.c \
				builtins/cd.c \
				builtins/cd_utils.c \
				builtins/exit.c \
				builtins/exit_utils.c \
				builtins/pwd.c \
				builtins/export.c

HEADER_FILE	= minishell_includes.h

SRCS_DIR	= ./srcs/
INC_DIR		= ./includes/

LIBFT		= ./libft/libft.a
LIBFT_PATH	= ./libft

SRCS		= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS		= ${SRCS:.c=.o}
HEADER		= $(addprefix ${INC_DIR}, ${HEADER_FILE})

CC			= cc
CC_FLAGS	= -Wall -Wextra -Werror -g

LINKS		= -lreadline

RM			= rm -f

%.o : %.c	${HEADER}
			${CC} ${CC_FLAGS} -I${INC_DIR} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CC_FLAGS} -I${INC_DIR} ${LINKS} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

${LIBFT}:	
			make -C ${LIBFT_PATH}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${OBJS} ${BONUS_OBJS}
			@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:		clean
			make -C ${LIBFT_PATH} fclean
			${RM} ${NAME} ${NAME_BONUS}
			@echo "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY: 	all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
