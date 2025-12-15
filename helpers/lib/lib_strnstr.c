/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/15 15:39:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	h;

	if ((little == NULL || big == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		h = 0;
		while (little[h] != '\0' && big[i + h] == little[h] && i + h < len)
			h++;
		if (little[h] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
