/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/05 12:01:09 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
//fds[0] = infile_fd, fds[1] = outfile_fd , fds[2] = pipe_in
int	multipipex(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	int	fds[3];
	int	i;
	int	child_pid;
	int last_pid;
	int status;

	file_opening(fds, argc, argv);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			open_pipe(pipe_fd, fds);
		child_pid = fork();
		if (child_pid == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (i == argc - 4)
			last_pid = child_pid;
		if (child_pid == 0)
		{
			pipe_management(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 2);
		}
		parent_pipe_management(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		continue ;
	return ((status >> 8) & 0xFF);
}
