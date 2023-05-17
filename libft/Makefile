# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:22:26 by nibenoit          #+#    #+#              #
#    Updated: 2023/05/17 14:36:30 by nwyseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	get_next_line.c\
	ft_strcmp.c\
	ft_printf_fd.c\
	ft_printf_utils_fd.c
OBJS = ${SRCS:.c=.o}
SRCSBONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
OBJSBONUS = ${SRCSBONUS:.c=.o}
AR = ar -rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: ${NAME}

${NAME}: ${OBJS} ${OBJSBONUS}
	${AR} ${NAME} ${OBJS} ${OBJSBONUS}

bonus: ${OBJS} ${OBJSBONUS}
	${AR} ${NAME} ${OBJS} ${OBJSBONUS}

.o: .c
	${CC} -c ${CFLAGS} $< -o $@

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) ${SRCSBONUS}
	gcc -nostartfiles -shared -o libft.so $(OBJS) ${OBJSBONUS}

clean:
	rm -f ${OBJS} ${OBJSBONUS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: clean fclean re all