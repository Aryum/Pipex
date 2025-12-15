/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:07:04 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/12 13:56:32 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	errno_exit_close(t_data data, int *fd, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		safe_close(fd[i]);
		i++;
	}
	errno_exit(data);
}

void	errno_exit(t_data data)
{
	perror("ERROR");
	clear_data(data);
	exit(errno);
}

int	error_parrams(void)
{
	lib_putstr_fd("ERROR: not enough paramenters\n", 2);
	return (1);
}

int	error_data(void)
{
	lib_putstr_fd("ERROR: couldn't set the necessary data\n", 2);
	return (1);
}
