/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 20:22:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**find_paths(char **envp)
{
	int	i;
	char	*path;
	char	**paths;

	i = 0;
	paths = NULL;
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
void	pipe_management(int i, int argc, int *fds, int *pipe_fd)
{
	dup2(fds[2] , 0);
	if (i < argc - 4)
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

void	exec_cmd(int i, char **argv, char **envp, int offset)
{
	char	**cmds;
	char	**paths;
	char	*pathname;

	cmds = ft_split(argv[offset + i], ' ');
	paths = find_paths(envp);
	pathname = check_access_pathname(paths, cmds[0]);
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
