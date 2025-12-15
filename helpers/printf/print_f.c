/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:44:46 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/04 13:23:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	formatstr(char c, va_list args, int *counter)
{
	if (c == 'c')
		h_put_char(va_arg(args, int), counter);
	else if (c == 's')
		h_put_str(va_arg(args, char *), counter);
	else if (c == 'p')
		h_put_ptr(va_arg(args, void *), counter);
	else if (c == 'd' || c == 'i')
		h_put_int(va_arg(args, int), counter);
	else if (c == 'u')
		h_put_uint(va_arg(args, unsigned int), counter);
	else if (c == 'x')
		h_put_uintbase(va_arg(args, unsigned int), "0123456789abcdef", counter);
	else if (c == 'X')
		h_put_uintbase(va_arg(args, unsigned int), "0123456789ABCDEF", counter);
	else if (c == '%')
		h_put_char('%', counter);
	else
		*counter = -1;
}

int	print_f(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	arg_v;

	if (str == NULL || write(1, 0, 0) == -1)
		return (-1);
	ret = 0;
	i = 0;
	va_start(arg_v, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			h_put_char(str[i], &ret);
		else
		{
			formatstr(str[i + 1], arg_v, &ret);
			if (ret != -1)
				i++;
			else
				break ;
		}
		i++;
	}
	va_end(arg_v);
	return (ret);
}
