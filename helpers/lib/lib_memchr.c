/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:30:07 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:30:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	*lib_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_c;
	unsigned char	c_c;

	i = 0;
	c_c = (unsigned char)c;
	s_c = (unsigned char *)s;
	while (i < n)
	{
		if (s_c[i] == c_c)
			return (&s_c[i]);
		i++;
	}
	return (NULL);
}
