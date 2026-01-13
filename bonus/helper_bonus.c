/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 20:07:04 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*new_str;
	int		i;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(s1);
	return (new_str);
}

void	get_first_command(int fd_read, char *limiter, int fd_write)
{
	char	buf[1];
	char	*line;

	line = ft_strdup("");
	write(1, "codehere>", 9);
	while (read(fd_read, buf, 1) > 0)
	{
		if (buf[0] == '\n')
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& line[ft_strlen(limiter)] == '\0')
			{
				free(line);
				break ;
			}
			write(fd_write, line, ft_strlen(line));
			write(fd_write, "\n", 1);
			free(line);
			line = ft_strdup("");
			write(1, "codehere>", 9);
		}
		else
			line = ft_strjoin_char(line, buf[0]);
	}
}

void	pipe_management_append(int i, int argc, int *fds, int *pipe_fd)
{
	dup2(fds[2], 0);
	if (i < argc - 5)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	else
		dup2(fds[1], 1);
	close(fds[2]);
	close(fds[1]);
}

void	parent_pipe_management_append(int *fds, int *pipe_fd, int argc, int i)
{
	close(fds[2]);
	if (i < argc - 5)
	{
		close(pipe_fd[1]);
		fds[2] = pipe_fd[0];
	}
}

void	file_opening_append(int	*fds, char **argv, int argc)
{
	int	pipe_temp_fd[2];

	fds[0] = 0;
	open_pipe(pipe_temp_fd, fds);
	get_first_command(fds[0], argv[2], pipe_temp_fd[1]);
	close(pipe_temp_fd[1]);
	fds[2] = pipe_temp_fd[0];
	fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fds[1] == -1)
		exit_error("File Opening Error", fds, NULL);
}
