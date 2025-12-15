/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:56:41 by ricsanto          #+#    #+#             */
/*   Updated: 2025/09/23 16:34:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/header.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	if (argc < 5)
		return (error_parrams());
	data = create_data(argc, argv, envp);
	if (data.cmd_paths == NULL || data.cmd_arr == NULL)
		return (clear_data(data), error_data());
	exec_first(&data);
	i = 1;
	while (i < data.cmd_count - 1)
	{
		exec_base(&data, i);
		i++;
	}
	exec_last(data, i);
	wait_all(data);
	clear_data(data);
}
