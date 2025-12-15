/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_putendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:57:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/06/06 11:31:44 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	lib_putendl_fd(char *s, int fd)
{
	if (fd >= 0 && s != NULL)
	{
		write(fd, s, lib_strlen(s));
		write(fd, "\n", 1);
	}
}
