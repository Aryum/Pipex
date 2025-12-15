/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:33:28 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:32:44 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*lib_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	ret = lib_strdup(s);
	i = 0;
	if (ret != NULL && f != NULL)
	{
		while (ret[i] != '\0')
		{
			ret[i] = f(i, ret[i]);
			i++;
		}
	}
	return (ret);
}
