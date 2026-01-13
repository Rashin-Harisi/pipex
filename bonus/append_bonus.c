/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 20:07:21 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
// fds[0] = infile_fd , fds[1]= outfile_fd , fds[2] =pipe_in
// pids[0] = child_pid , pids[1] = last_pid
int	append(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	int	pids[2];
	int	fds[3];
	int	i;

	file_opening_append(fds, argv, argc);
	i = -1;
	while (++i < argc - 4)
	{
		if (i < argc - 5)
			open_pipe(pipe_fd, fds);
		pids[0] = fork();
		if (pids[0] == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (i == argc - 5)
			pids[1] = pids[0];
		if (pids[0] == 0)
		{
			pipe_management_append(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 3);
		}
		parent_pipe_management_append(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	return (wait_all(pids[1]));
}
