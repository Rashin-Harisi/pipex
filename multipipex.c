/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 14:44:38 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	multipipex(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	int	fds[3];
	int	i;
	int	pids[2];

	file_opening(fds, argc, argv);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			open_pipe(pipe_fd, fds);
		pids[0] = fork();
		if (pids[0] == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (i == argc - 4)
			pids[1] = pids[0];
		if (pids[0] == 0)
		{
			pipe_management(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 2);
		}
		parent_pipe_management(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	return (wait_all(pids[1]));
}
