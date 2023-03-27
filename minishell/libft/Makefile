SRCS = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_split.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putstr_fd.c\
	ft_strjoin.c\
	ft_substr.c\
	ft_strncmp.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_strlcpy.c\
	ft_putnbr_fd.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strtrim.c\
	ft_calloc.c\
	ft_strmapi.c\
	ft_striteri.c\

PRINTF = ft_printf_utils.c \
	ft_printf.c \

GNL = get_next_line.c \
	get_next_line_utils.c \

BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${BONUS:.c=.o}
OBJSPRINTF = ${PRINTF:.c=.o}
OBJSGNL = ${GNL:.c=.o}

AR = ar -rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: ${NAME}

${NAME} : ${OBJS} ${OBJSPRINTF} ${OBJSBONUS} ${OBJSGNL}
	@${AR} ${NAME} ${OBJS} ${OBJSPRINTF} ${OBJSBONUS} ${OBJSGNL}

.o: .c
	@${CC} -c ${CFLAGS} $< -o $@

bonus: ${OBJS} ${OBJSBONUS} ${OBJSPRINTF} ${OBJSGNL}
	@${AR} ${NAME} ${OBJS} ${OBJSBONUS} ${OBJSPRINTF} ${OBJSGNL}

clean:
	@rm -f ${OBJS} ${OBJSBONUS} ${OBJSPRINTF} ${OBJSGNL}

fclean: clean
	@rm -f ${NAME}

re: fclean 
	@${NAME}

.PHONY: clean fclean re all bonus