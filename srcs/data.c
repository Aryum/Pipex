/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:44:30 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/14 13:04:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**get_cmdpath(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL && lib_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (envp[i] != NULL)
		return (lib_split(envp[i] + 5, ':'));
	else
		return (NULL);
}

t_data	create_data(int argc, char **agrv, char **envp)
{
	t_data	ret;

	ret.cmd_paths = get_cmdpath(envp);
	ret.cmd_arr = get_commands(argc, agrv, ret.cmd_paths);
	ret.cmd_count = argc - 3;
	ret.envp = envp;
	ret.file_in = agrv[1];
	ret.file_out = agrv[argc - 1];
	return (ret);
}

void	clear_data(t_data data)
{
	lib_split_clean(data.cmd_paths);
	clear_commands(data.cmd_arr, data.cmd_count);
}
