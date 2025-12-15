/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:58:02 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 17:30:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	char	*retval;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	s1_len = lib_strlen(s1);
	retval = lib_calloc(s1_len + lib_strlen(s2) + 1, sizeof(char));
	if (retval != NULL)
	{
		while (s1[i] != '\0')
		{
			retval[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			retval[s1_len + i] = s2[i];
			i++;
		}
		retval[s1_len + i] = '\0';
	}
	return (retval);
}
