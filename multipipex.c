/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/11 15:02:52 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
//fds[0] = infile_fd, fds[1] = outfile_fd , fds[2] = pipe_in 
//pids[0] = child_pid , pids[1] = last_pid
char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = find_paths(envp);
	if (!paths)
		return (NULL);
	path = check_access_pathname(paths, cmd);
	free_array(paths);
	return (path);
}

int	wait_all(int last_pid)
{
	int	status;
	int	exit_code;

	waitpid(last_pid, &status, 0);
	if (((status) & 0x7f) == 0)
		exit_code = (status >> 8) & 0xFF;
	else
		exit_code = 1;
	while (wait(NULL) > 0)
		continue ;
	return (exit_code);
}

char	*trim_helper(char *str)
{
	size_t	len;
	char	*new;
	int	i;
	int	j;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	j = 0;
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (str);
	if (len >= 2 && ((str[0] == '\'' || str[0] == '\"') && str[len - 1] == str[0]))
	{
		i = 1;
		len = len - 1;
	}
	while (i < (int)len)
	{
		if (str[i] == '\\' && str[i + 1])
			i++;
		new[j++] = str[i++];
	}
	new[j] = '\0';
	free(str);
	return (new);
}

void	trim_cmds(char **cmds)
{
	int	i;

	i = 0;
	if (!cmds)
		return ;
	while (cmds[i])
	{
//		dprintf(2, "BEFORE TRIM: [%s]\n", cmds[i]);
		cmds[i] = trim_helper(cmds[i]);
		cmds[i] = trim_helper(cmds[i]);
		i++;
	}
}

int	multipipex(int argc, char *argv[], char **envp)
{
	int	pipe_fd[2];
	int	fds[3];
	int	i;
	int	pids[2];

	file_opening(fds, argc, argv);
	i = -1;
	while (++i < argc - 3)
	{
		if (i < argc - 4)
			open_pipe(pipe_fd, fds);
		pids[0] = fork();
		if (pids[0] == -1)
			exit_error("Fork Error", fds, pipe_fd);
		if (i == argc - 4)
			pids[1] = pids[0];
		if (pids[0] == 0)
		{
			pipe_management(i, argc, fds, pipe_fd);
			exec_cmd(i, argv, envp, 2);
		}
		else
			parent_pipe_management(fds, pipe_fd, argc, i);
	}
	close(fds[1]);
	return (wait_all(pids[1]));
}
