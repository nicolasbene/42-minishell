# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 21:18:35 by nwyseur           #+#    #+#              #
#    Updated: 2023/04/27 14:52:46 by nwyseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS_FILES	= main.c \
				execution/pipex.c \
				execution/execute_command.c \
				execution/get_path.c \
				execution/handle_redirects.c \
				execution/create_command.c \
				execution/free_command.c \
				execution/list_to_tab.c \
				execution/execution.c \
				execution/open_fd.c \
				print_error.c \
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
				parser/variable_exp_split.c \
				parser/variable_exp_split_utils.c \
				parser/quote_management.c \
				builtins/env.c \
				builtins/echo.c

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
