/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 20:13:59 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	multipipex(int argc, char *argv[],char **envp)
{
	int	pipe_fd[2];
	int	fds[3]; //fds[0] = infile_fd, fds[1] = outfile_fd , fds[2] = pipe_in
	int	i;
	pid_t	child_pid;

	file_opening(fds, argc, argv);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			open_pipe(pipe_fd, fds);
		child_pid = fork();
		if (child_pid == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (child_pid == 0)
		{
			pipe_management(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 2);
		}
		parent_pipe_management(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	while (wait(NULL) > 0);
}
