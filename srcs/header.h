/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:33:08 by ricsanto          #+#    #+#             */
/*   Updated: 2025/08/12 14:58:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "../helpers/lib/lib.h"

typedef struct s_command
{
	pid_t	pid;
	char	*path;
	char	**args;
}	t_command;

typedef struct s_data
{
	t_command	*cmd_arr;
	char		**envp;
	char		**cmd_paths;
	char		*file_in;
	char		*file_out;
	int			cmd_count;
}	t_data;

void		clear_data(t_data data);

t_data		create_data(int agrc, char **argv, char **envp);

t_command	*get_commands(int agrc, char **argv, char **paths);

void		clear_commands(t_command *cmd_arr, int len);

int			print_f(const char *str, ...);

void		exec_first(t_data *data);

void		exec_base(t_data *data, int i);

void		exec_last(t_data data, int i);

void		close_pipe(int fd[2]);

int			safe_dup(int fd_1, int fd_2);

int			safe_fork(pid_t *pid);

void		safe_close(int fd);

void		errno_exit(t_data data);

void		errno_exit_close(t_data data, int *fd, int count);

int			is_cmd_valid(t_command cmd);

void		debug(t_data data);

void		wait_all(t_data data);

int			error_data(void);

int			error_parrams(void);

void		parent_process(t_data *data, int fd[2]);

void		child_process(t_data *data, int i, int fd[2]);

void		parent_process(t_data *data, int fd[2]);

void		exec_cmd(t_data data, int i);

#endif