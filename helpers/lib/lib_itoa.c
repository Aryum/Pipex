/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:30:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:30:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	nbcount(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*lib_itoa(int n)
{
	int		len;
	char	*ret;
	long	nbr;

	nbr = (long)n;
	len = nbcount(nbr);
	if (nbr < 0)
		len++;
	ret = lib_calloc(len + 1, sizeof(char));
	if (ret != NULL)
	{
		len -= 1;
		if (nbr < 0)
		{
			ret[0] = '-';
			nbr *= -1;
		}
		while (len >= 0 && ret[len] != '-')
		{
			ret[len] = nbr % 10 + '0';
			len -= 1;
			nbr /= 10;
		}
	}
	return (ret);
}
