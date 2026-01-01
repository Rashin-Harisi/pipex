/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/01 15:50:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
// fds[0] = infile_fd , fds[1]= outfile_fd , fds[2] =pipe_in
void	append(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	int	child_pid;
	int	fds[3];
	int	i;

	file_opening_append(fds, argv, argc);
	i = -1;
	while (++i < argc - 4)
	{
		if (i < argc - 5)
			open_pipe(pipe_fd, fds);
		child_pid = fork();
		if (child_pid == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (child_pid == 0)
		{
			pipe_management_append(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 3);
		}
		parent_pipe_management_append(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	while (wait(NULL) > 0)
		continue ;
}
