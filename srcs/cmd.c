/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:00:06 by ricsanto          #+#    #+#             */
/*   Updated: 2025/07/14 13:10:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*get_path(char **paths, char *cmd)
{
	char	*cur_dir;
	char	*cur_path;
	int		i;

	i = 0;
	if (cmd == NULL)
		return (NULL);
	while (paths[i] != NULL)
	{
		cur_dir = lib_strjoin(paths[i], "/");
		cur_path = lib_strjoin(cur_dir, cmd);
		free(cur_dir);
		if (cur_path == NULL || access(cur_path, F_OK) == 0)
			return (cur_path);
		free(cur_path);
		i++;
	}
	return (NULL);
}

static t_command	create_command(char **paths, char *cmd)
{
	t_command	ret;

	ret.args = lib_split(cmd, ' ');
	ret.pid = -1;
	if (ret.args != NULL)
		ret.path = get_path(paths, ret.args[0]);
	else
		ret.path = NULL;
	return (ret);
}

t_command	*get_commands(int agrc, char **argv, char **paths)
{
	t_command	*arr;
	int			i;

	if (agrc < 5 || paths == NULL)
		return (NULL);
	i = 2;
	arr = malloc((agrc - 3) * sizeof(t_command));
	if (arr != NULL)
	{
		while (i < agrc - 1)
		{
			arr[i - 2] = create_command(paths, argv[i]);
			i++;
		}
	}
	return (arr);
}

int	is_cmd_valid(t_command cmd)
{
	return (cmd.path != NULL && cmd.args != NULL);
}

void	clear_commands(t_command *cmd_arr, int len)
{
	int	i;

	if (cmd_arr == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		if (cmd_arr[i].path != NULL)
			free(cmd_arr[i].path);
		lib_split_clean(cmd_arr[i].args);
		i++;
	}
	free(cmd_arr);
}
