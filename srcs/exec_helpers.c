/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:22:10 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/12 14:55:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_cmd(t_data data, int i)
{
	if (!is_cmd_valid(data.cmd_arr[i]))
	{
		clear_data(data);
		lib_putstr_fd("ERROR: Invalid command\n", 2);
		exit(0);
	}
	if (execve(data.cmd_arr[i].path, data.cmd_arr[i].args, data.envp) == -1)
		errno_exit(data);
}

void	child_process(t_data *data, int i, int fd[2])
{
	if (!safe_dup(fd[1], STDOUT_FILENO))
		errno_exit_close(*data, fd, 2);
	close_pipe(fd);
	exec_cmd(*data, i);
}

void	parent_process(t_data *data, int fd[2])
{
	if (!safe_dup(fd[0], STDIN_FILENO))
		errno_exit_close(*data, fd, 2);
	close_pipe(fd);
}