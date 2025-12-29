/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/29 14:54:37 by rabdolho         ###   ########.fr       */
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

int main(int argc, char *argv[],char **envp)
{
	int	pipe_fd[2];
	pid_t	child_first_pid;
	pid_t	child_second_pid;
	int	pipex;
	int	infile_fd;
	int	outfile_fd;

	if (argc < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40));
	pipex = pipe(pipe_fd);
	if (pipex == -1)
		exit(1);
	child_first_pid = fork();
	if (child_first_pid == 0)
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			exit(1);
		dup2(infile_fd , 0);
		dup2(pipe_fd[1] , 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(infile_fd);
		char **cmds = ft_split(argv[2], ' ');
		char **paths = find_paths(envp);
		char *pathname = check_access_pathname(paths, cmds[0]);
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
	child_second_pid = fork();
	if (child_second_pid == 0)
	{
		outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(outfile_fd == -1)
			exit(1);
		dup2(pipe_fd[0], 0);
		dup2(outfile_fd, 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile_fd);
		char **cmds = ft_split(argv[3], ' ');
		char **paths = find_paths(envp);
		char *pathname = check_access_pathname(paths, cmds[0]);
		if (!pathname)
		{
			free_array(cmds);
			free_array(paths);
			write(2, "Command not found!\n", 19);
			exit(1);
		}
		execve(pathname,cmds, envp);
		free(pathname);
		free_array(cmds);
		free_array(paths);
		exit(1);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(child_first_pid, NULL, 0);
	waitpid(child_second_pid, NULL, 0);
	return 0;
}
