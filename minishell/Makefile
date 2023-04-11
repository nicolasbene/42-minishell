# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 21:18:35 by nwyseur           #+#    #+#              #
#    Updated: 2023/04/11 18:12:52 by nibenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

SRCS_FILES	:= main.c \
				pipex.c \
				exec.c \
				get_path.c \
				redir.c \
				create_command.c \
				free_command.c \
				env.c \
				list_to_tab.c

HEADER_FILE	:= minishell.h

SRCS_DIR	:= ./srcs/
INC_DIR		:= ./includes/

LIBFT		:= ./libft/libft.a
LIBFT_PATH	:= ./libft

SRCS		:= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS		:= ${SRCS:.c=.o}
HEADER		:= $(addprefix ${INC_DIR}, ${HEADER_FILE})

CC			:= cc
CC_FLAGS	:= -Wall -Wextra -Werror -g

LINKS	=	-lreadline

RM			:= rm -f

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
