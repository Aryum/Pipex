/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:09:06 by ricsanto          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_substr(char const *s, unsigned int start, size_t len)
{
	char	*retval;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = lib_strlen(s);
	if (start >= size)
		return (lib_strdup(""));
	if (len > size - start)
		len = size - start ;
	retval = lib_calloc(len + 1, sizeof(char));
	if (retval != NULL)
		lib_strlcpy(retval, &s[start], len + 1);
	return (retval);
}
