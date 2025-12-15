/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h_put_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:40:28 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/09 17:41:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	h_put_int(int n, int *counter)
{
	int	correction;

	correction = 0;
	if (n < 0)
	{
		h_put_char('-', counter);
		if (n == -2147483648)
			correction = 1;
		n = -1 * (n + correction);
	}
	if (n > 9)
		h_put_int(n / 10, counter);
	h_put_char(n % 10 + '0' + correction, counter);
}

void	h_put_uint(unsigned int i, int *counter)
{
	if (i > 9)
		h_put_uint(i / 10, counter);
	h_put_char(i % 10 + '0', counter);
}
