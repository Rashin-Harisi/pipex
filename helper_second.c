/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/01 15:54:33 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exit_error(char *str, int *fds, int *pipe_fd)
{
	perror(str);
	if (fds)
	{
		close(fds[0]);
		close(fds[1]);
		close(fds[2]);
	}
	if (pipe_fd)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	exit(1);
}

void	file_opening(int *fds, int argc, char **argv)
{
	fds[0] = open(argv[1], O_RDONLY);
	fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[0] == -1 || fds[1] == -1)
		exit_error("Error in opening files", fds, NULL);
	fds[2] = fds[0];
}

void	open_pipe(int *pipe_fd, int *fds)
{
	int	pipex;

	pipex = pipe(pipe_fd);
	if (pipex == -1)
		exit_error("Pipe Error", fds, pipe_fd);
}

void	parent_pipe_management(int *fds, int *pipe_fd, int argc, int i)
{
	close(fds[2]);
	if (i < argc - 4)
	{
		close(pipe_fd[1]);
		fds[2] = pipe_fd[0];
	}
}
