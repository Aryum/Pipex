/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:02:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 18:05:38 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		lib_isalpha(int i);

int		lib_isdigit(int c);

int		lib_isalnum(int c);

int		lib_isascii(int c);

int		lib_isprint(int c);

int		lib_toupper(int c);

int		lib_tolower(int c);

size_t	lib_strlcat(char *dst, const char *src, size_t size);

size_t	lib_strlen(const char *s);

void	*lib_memset(void *s, int c, size_t n);

void	lib_bzero(void *s, size_t n);

size_t	lib_strlcpy(char *dst, const char *src, size_t size);

int		lib_strncmp(const char *s1, const char *s2, size_t n);

int		lib_memcmp(const void *s1, const void *s2, size_t n);

void	*lib_memchr(const void *s, int c, size_t n);

char	*lib_strchr(const char *s, int c);

char	*lib_strrchr(const char *s, int c);

void	*lib_memcpy(void *dest, const void *src, size_t n);

void	*lib_memmove(void *dest, const void *src, size_t n);

char	*lib_strnstr(const char *big, const char *little, size_t len);

int		lib_atoi(const char *nptr);

void	*lib_calloc(size_t nmemb, size_t size);

char	*lib_strdup(const char *s);

char	*lib_substr(char const *s, unsigned int start, size_t len);

char	*lib_strjoin(char const *s1, char const *s2);

char	*lib_strtrim(char const *s1, char const *set);

void	lib_split_clean(char **arr);

char	**lib_split(char const *s, char c);

char	*lib_itoa(int n);

char	*lib_strmapi(char const *s, char (*f)(unsigned int, char));

void	lib_striteri(char *s, void (*f)(unsigned int, char*));

void	lib_putchar_fd(char c, int fd);

void	lib_putstr_fd(char *s, int fd);

void	lib_putendl_fd(char *s, int fd);

void	lib_putnbr_fd(int n, int fd);

#endif
