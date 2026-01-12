/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fourth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 17:25:03 by rabdolho         ###   ########.fr       */
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
		if (envp && *envp)
		command_error(cmds[0]);
		free_array(cmds);
		if (pathname)
			free(pathname);
		if (argv[offset + i + 1] == NULL)
			exit(127);
		exit(0);
	}
	execve(pathname, cmds, envp);
	perror("execve");
	free(pathname);
	free_array(cmds);
	exit(126);
}
