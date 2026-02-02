/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/20 13:33:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

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

void	command_error(char *cmd)
{
	char	*temp;
	char	*message;

	temp = ft_strjoin("pipex: ", cmd);
	if (!temp)
		return ;
	message = ft_strjoin(temp, ": command not found\n");
	free(temp);
	if (!message)
		return ;
	write(2, message, ft_strlen(message));
	free(message);
}

void	file_opening(int *fds, int argc, char **argv, char **envp)
{
	fds[0] = open(argv[1], O_RDONLY);
	fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[0] == -1)
	{
		if (envp && *envp)
		{
			ft_putstr_fd("pipex: ", 2);
			perror(argv[1]);
		}
		fds[0] = open("/dev/null", O_RDONLY);
	}
	if (fds[1] == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[argc - 1]);
		if (fds[0] != -1)
			close(fds[0]);
		exit(1);
	}
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
	if (fds[2] != 0)
		close(fds[2]);
	if (i < argc - 4)
	{
		close(pipe_fd[1]);
		fds[2] = pipe_fd[0];
	}
	else
		fds[2] = -1;
}
