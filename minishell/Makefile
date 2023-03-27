# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 21:18:35 by nwyseur           #+#    #+#              #
#    Updated: 2023/02/27 12:48:04 by nwyseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
NAME_BONUS	:= pipex_bonus

SRCS_FILES	:= main_copy.c \
				error_management.c \
				free_management.c \
				utils_copy.c \

BONUS_FILES	:= main_bonus.c \
				error_management_bonus.c \
				free_management_bonus.c \
				utils_bonus.c \
				here_doc.c \

HEADER_FILE_BONUS := pipex_bonus.h

HEADER_FILE	:= pipex.h

SRCS_DIR	:= ./srcs/
INC_DIR		:= ./includes/

BONUS_DIR	:= ./srcs_bonus/

LIBFT		:= ./libft/libft.a
LIBFT_PATH	:= ./libft

SRCS		:= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS		:= ${SRCS:.c=.o}
HEADER		:= $(addprefix ${INC_DIR}, ${HEADER_FILE})

BONUS_SRCS	:= $(addprefix ${BONUS_DIR}, ${BONUS_FILES})
BONUS_OBJS	:= ${BONUS_SRCS:.c=.o}
BONUS_HEADER := $(addprefix ${INC_DIR}, ${HEADER_FILE_BONUS})

CC			:= cc
CC_FLAGS	:= -Wall -Wextra -Werror

RM			:= rm -f

%.o : %.c	${HEADER}
			${CC} ${CC_FLAGS} -I${INC_DIR} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CC_FLAGS} -I${INC_DIR} -o ${NAME} ${OBJS} ${LIBFT}
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

${NAME_BONUS}: ${BONUS_OBJS} ${LIBFT}
				${CC} ${CC_FLAGS} -I${INC_DIR} -o ${NAME_BONUS} ${BONUS_OBJS} ${LIBFT}
				@echo "$(GREEN)$(NAME_BONUS) created!$(DEFAULT)"

${LIBFT}:	
			make -C ${LIBFT_PATH}

bonus:		${NAME_BONUS}

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
