/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:28:23 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/12 13:06:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	safe_wait(t_data data, pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (status != 0 && WIFEXITED(status))
	{
		perror("ERROR");
		clear_data(data);
		exit(WEXITSTATUS(status));
	}
}

void	wait_all(t_data data)
{
	int	i;

	i = 1;
	while (i < data.cmd_count)
	{
		safe_wait(data, data.cmd_arr[i].pid);
		i++;
	}
}

void	close_pipe(int fd[2])
{
	safe_close(fd[0]);
	safe_close(fd[1]);
}

int	safe_dup(int fd_1, int fd_2)
{
	if (dup2(fd_1, fd_2) == -1)
		return (0);
	return (1);
}

int	safe_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		return (0);
	else
		return (1);
}
