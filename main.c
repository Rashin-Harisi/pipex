/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/29 12:49:34 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	**paths(char **envp)
{
	int	i,j;
	char	*path;
	char	**paths;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i],"PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			paths = ft_split(path, ":");
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
		temp = ft_strjoin(path[i],"/");
		pathname = ft_strjoin(temp , cmd);
		free(temp);
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}


int main(int argc, char *argv[],char **envp)
{
	int	pipe_fd[2];
	pid_t	child_first_pid;
	int	pipex;
	int	infile_fd;

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
		char **cmds = ft_split(argv[2], " ");
		char **paths = paths(envp);
		char *pathname = check_access_pathname(paths, cmd[0]);
		execve(pathname, cmds, envp);		
	}
	
	return 0;
}
