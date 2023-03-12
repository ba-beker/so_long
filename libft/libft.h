/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:21:17 by mobabeke          #+#    #+#             */
/*   Updated: 2023/03/11 17:36:55 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

# define BUFFER_SIZE (1)
// # define FOPEN_MAX (1025)
long	ft_atoi(const char *str);
void	ft_bzero(void *s, int nbyte);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_isalnum(int x);
int		ft_isalpha(int c);
int		ft_isascii(int x);
int		ft_isdigit(int x);
int		ft_isprint(int x);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t numBytes);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
int		gnl(int fd, char **str);
// get_next_line
char	*new_line(const char *str, int c);
char	*get_next_line(int fd);
// ft_printf
int		ft_check_format(va_list arg, char c);
int		ft_converto_c(va_list arg);
int		ft_converto_s(va_list arg);
int		ft_converto_di(va_list arg);
int		ft_converto_x(va_list arg);
void	ft_putstr_fd(char *s, int fd);
int		ft_converto_hex(size_t n);
int		ft_converto_cx(va_list arg);
int		ft_converto_u(va_list arg);
int		ft_converto_p(va_list arg);
int		ft_converto_hexupper(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_intlen(int x);
void	ft_unputnbr_fd(unsigned int n, int fd);
int		ft_unintlen(unsigned int i);
int		printpers(char i);

#endif