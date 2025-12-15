/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:06:31 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/13 14:37:33 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_env(t_data data)
{
	int	i;

	i = 0;
	print_f("Env Paths\n");
	while (data.cmd_paths[i] != NULL)
	{
		print_f("	%s\n", data.cmd_paths[i]);
		i++;
	}
}

static void	print_agrs(t_data data)
{
	int	i;
	int	h;

	i = 0;
	while (i < data.cmd_count)
	{
		print_f("Path\n");
		print_f("	%s\n", data.cmd_arr[i].path);
		if (data.cmd_arr[i].path != NULL)
		{
			print_f("Args\n");
			h = 0;
			while (data.cmd_arr[i].args[h] != NULL)
			{
				print_f("	%s\n", data.cmd_arr[i].args[h]);
				h++;
			}
		}
		print_f("\n\n");
		i++;
	}
}

void	debug(t_data data)
{
	if (data.cmd_paths == NULL || data.cmd_arr == NULL)
		return ;
	print_env(data);
	print_agrs(data);
}
