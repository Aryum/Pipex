/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:22:37 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/14 13:17:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_strrchr(const char *s, int c)
{
	size_t	i;

	i = lib_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (NULL);
}
