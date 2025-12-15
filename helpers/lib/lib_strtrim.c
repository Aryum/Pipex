/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:28:39 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/17 18:39:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	ischarset(char c, char const *set)
{
	size_t	i;

	i = 0;
	if (set != NULL)
	{
		while (set[i] != '\0')
		{
			if (c == set[i])
				return (1);
			i++;
		}
	}
	return (0);
}

static size_t	charsetcount(char const *s1, size_t s1_len, char const *set)
{
	size_t	retval;

	retval = 0;
	while (s1[retval] != '\0' && ischarset(s1[retval], set))
		retval ++;
	if (retval != s1_len)
	{
		while (ischarset(s1[s1_len - 1], set))
		{
			s1_len --;
			retval++;
		}
	}
	return (retval);
}

char	*lib_strtrim(char const *s1, char const *set)
{
	char		*retval;
	size_t		i;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = lib_strlen(s1);
	len = len - charsetcount(s1, len, set) + 1;
	retval = lib_calloc(len, sizeof(char));
	if (retval != NULL)
	{
		while (s1[i] != '\0' && ischarset(s1[i], set))
			i++;
		lib_strlcpy(retval, &s1[i], len);
	}
	return (retval);
}
