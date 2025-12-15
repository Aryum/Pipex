/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/04 13:22:31 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

void	h_put_char(int c, int *counter);

void	h_put_int(int n, int *counter);

void	h_put_ulongbase(unsigned long nbr, char *base, int *counter);

void	h_put_uintbase(unsigned int nbr, char *base, int *counter);

void	h_put_ptr(void *ptr, int *counter);

void	h_put_str(char *str, int *counter);

void	h_put_uint(unsigned int i, int *counter);

int		h_strlen(const char *s);

int		print_f(const char *string, ...);

#endif
