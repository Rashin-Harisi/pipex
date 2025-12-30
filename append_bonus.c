/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuc_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 16:06:26 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**find_paths(char **envp)
{
	int	i;
	char	*path;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i],"PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			paths = ft_split(path, ':');
		}
		i++;	  
	}
	return (paths);
}

char	*check_access_pathname(char **paths, char *cmd)
{
	int	i;
	char	*temp;
	char	*pathname;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		pathname = ft_strjoin(temp , cmd);
		free(temp);
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}

void free_array(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
char	*get_first_command(int fd,char *limiter)
{
	char	buf[1];
	char	*line;

	line = ft_srtdup("");
	while (read(fd, buf, 1) > 0)
	{
		if (fd[0] == '\n')
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
			line = ft_strdup("");
		}
		else
			line = ft_strjoin(line, buf[0]);
	}
}

int main(int argc, char *argv[],char **envp)
{
	int	pipe_temp_fd[2];
	int	pipe_fd[2];
	pid_t	child_pid;
	int	pipex;
	int	infile_fd;
	int	outfile_fd;

	if (argc < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40));
	if (ft_strncmp(argv[1], "here_doc" ,ft_strlen("hero_doc")) == 0)
	{
		infile_fd = 0;
		first_cmd = get_first_cmd(infile_fd,argv[2]);
		int temp_pipe = pipe(pipe_temp_fd);
		if (temp_pipe == -1)
			exit(1);
		int pipex = pipe(pipe_fd);
		if (pipex == -1)
			exit(1);
		child_first_pid = fork();
		if (child_first_pid == 0)
		{
			dup2(pipe_temp_fd[1], 0);
			close(pipe_fd[0]);
			dup2(pipe_fd[1],1);
			close(pipe_fd[1]);
			close(pipe_fd[0]);
			char **cmds = ft_split(first_cmd, ' ');
			char **paths = find_paths(envp);
			char *pathname = check_access_pathname(paths , cmds[0]);
			if (!pathname)
			{
				free_array(cmds);
				free_array(paths);
				write(2, "Command not found!\n", 19);
				exit(127);
			}
			execve(pathname, cmds, envp);
			free(pathname);
			free_array(cmds);
			free_array(paths);
			exit(1);
		}

		outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		//error of outfile open error
		int cmds_n = argc - 3;
		int i = 0;
		int pipe_in = infile_fd;
	}
	close(outfile_fd);
	while (wait(NULL) > 0);
	return 0;
}
