/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:28:42 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:28:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	lib_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		retval;

	sign = 1;
	retval = 0;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (lib_isdigit(nptr[i]))
	{
		retval += nptr[i] - '0';
		if (lib_isdigit(nptr[i + 1]))
			retval *= 10;
		i++;
	}
	return (retval * sign);
}
