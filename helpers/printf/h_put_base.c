/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_put_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:31:47 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/01 12:41:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	is_base_valid(char *str)
{
	int	i;
	int	j;

	if (str == NULL)
		return (0);
	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			if ((str[i] > 8 && str[i] <= '\r') || str[i] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	print_base(unsigned long nbr, char *base, int sz, int *c)
{
	if (nbr / sz != 0)
		print_base(nbr / sz, base, sz, c);
	h_put_char(base[nbr % sz], c);
}

void	h_put_ulongbase(unsigned long nbr, char *base, int *counter)
{
	if (is_base_valid(base))
		print_base(nbr, base, h_strlen(base), counter);
}

void	h_put_uintbase(unsigned int nbr, char *base, int *counter)
{
	if (is_base_valid(base))
		print_base(nbr, base, h_strlen(base), counter);
}
