/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:56 by nwyseur           #+#    #+#             */
/*   Updated: 2023/02/13 15:22:59 by nwyseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BASEX
#  define BASEX "0123456789abcdef"
# endif

# ifndef BASEXC
#  define BASEXC "0123456789ABCDEF"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *str, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *ptr, int x, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *hay, const char *nee, size_t n);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t		ft_trimlen(char const *str, char const *set);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_printf(const char *str, ...);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(long int c);
int			ft_putnbr_u(unsigned int c);
int			ft_putnbr_x(unsigned long c);
int			ft_putnbr_xc(unsigned int c);
int			ft_putnbr_p(unsigned long c);
int			ft_checkarg(int c, va_list ap);

char		*get_next_line(int fd);
char		*ft_getres(char *res, char *buff);
char		*ft_read_file(int fd, char *buff);
char		*ft_strjfree(char *buff, char *buff2);
char		*ft_strjoin_g(char *buff, char *buff2);
size_t		ft_strlen_g(char *str);
char		*ft_nextline(char *buff, char *res);
char		*ft_getline(char *buff);
int			ft_strchr_g(char *str, char c);
int			has_newline(char *s);

#endif