/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:07:12 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/12 14:59:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_first(t_data *data)
{
	int	fd[2];
	int	file_in;
	
	if (pipe(fd) == -1)
		errno_exit(*data);
	if (!safe_fork(&(data->cmd_arr[0].pid)))
		errno_exit_close(*data, fd, 2);
	if (data->cmd_arr[0].pid == 0)
	{
		file_in = open(data->file_in, O_RDONLY);
		if(file_in == -1 || !safe_dup(file_in, STDIN_FILENO))
		{
			safe_close(file_in);
			errno_exit_close(*data, fd, 2);
		}
		else
		{
			safe_close(file_in);
			exec_cmd(*data, 0);
		}
	}
	else
		parent_process(data, fd);
}

void	exec_base(t_data *data, int i)
{
	int	fd[2];

	if (pipe(fd) == -1)
		errno_exit(*data);
	if (!safe_fork(&(data->cmd_arr[i].pid)))
		errno_exit_close(*data, fd, 2);
	if (data->cmd_arr[i].pid == 0)
		child_process(data, i, fd);
	else
		parent_process(data, fd);
}

void	exec_last(t_data data, int i)
{
	int		out;

	if (!safe_fork(&(data.cmd_arr[i].pid)))
		errno_exit_close(data, &out, 1);
	if (data.cmd_arr[i].pid == 0)
	{
		out = open(data.file_out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (out != -1 && !safe_dup(out, STDOUT_FILENO))
			errno_exit_close(data, &out, 1);
		close(out);
		exec_cmd(data, i);
	}
	close(out);
}
