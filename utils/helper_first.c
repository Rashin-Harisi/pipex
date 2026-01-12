/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 10:57:43 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

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
	if (fds[2] == -1)
		exit(1);
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

char	**prepare_cmds(char *command)
{
	char	**cmds;

	if (ft_strchr(command, '/') && access(command, X_OK) == 0)
	{
		cmds = malloc(2 * (sizeof(char *)));
		if (!cmds)
			return (NULL);
		cmds[0] = ft_strdup(command);
		cmds[1] = NULL;
	}
	else
		cmds = cmds_split(command, ' ');
	return (cmds);
}

void	exec_cmd(int i, char **argv, char **envp, int offset)
{
	char	**cmds;
	char	*pathname;

	cmds = prepare_cmds(argv[offset + i]);
	if (!cmds)
		exit(0);
	if (!cmds[0])
	{
		free_array(cmds);
		exit(0);
	}
	pathname = get_path(cmds[0], envp);
	if (!pathname || access(pathname, X_OK) != 0)
	{
		command_error(cmds[0]);
		free_array(cmds);
		if (pathname)
			free(pathname);
		exit(127);
	}
	execve(pathname, cmds, envp);
	perror("execve");
	free(pathname);
	free_array(cmds);
	exit(126);
}
