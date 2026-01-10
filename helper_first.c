/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/10 17:32:43 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**find_paths(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*check_access_pathname(char **paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*pathname;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		pathname = ft_strjoin(temp, cmd);
		free(temp);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}

void	free_array(char **s)
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
	dup2(fds[2], 0);
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
	char	*pathname;

	cmds = cmds_split(argv[offset + i], ' ');
	if (!cmds || !cmds[0])
		exit(0);
	dprintf(2, "DEBUG: cmds[0] is %s\n", cmds[0]);
	if (cmds[1])
		dprintf(2, "DEBUG: cmds[1] is %s\n", cmds[1]);
	else
		dprintf(2, "DEBUG: cmds[1] is NULL\n");
	pathname = get_path(cmds[0], envp);
	if (!pathname || access(pathname, X_OK) != 0)
	{
		if (pathname)
			free(pathname);
		command_error(cmds[0]);
		free_array(cmds);
		if (!pathname)
			exit(127);
		if (access(pathname, X_OK) != 0)
			exit(126);
	}
	execve(pathname, cmds, envp);
	perror("execve");
	free(pathname);
	free_array(cmds);
	exit(126);
}
