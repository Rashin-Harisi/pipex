/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fourth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/14 10:10:00 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

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

void	cleanup_exec_cmd(char *pathname, char **cmds, char **argv, int status)
{
	if (status == 127)
		command_error(cmds[0]);
	else if (status == 126 && pathname)
		perror(cmds[0]);
	if (pathname)
		free(pathname);
	if (cmds)
		free_array(cmds);
	if (argv == NULL)
		exit(126);
	exit(status);
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
	if (!pathname)
	{
		if (argv[offset + i + 2] == NULL)
			cleanup_exec_cmd(NULL, cmds, argv, 127);
		cleanup_exec_cmd(NULL, cmds, argv, 0);
	}
	if (access(pathname, X_OK) != 0)
		cleanup_exec_cmd(pathname, cmds, argv, 126);
	execve(pathname, cmds, envp);
	perror("execve");
	cleanup_exec_cmd(pathname, cmds, NULL, 126);
}
