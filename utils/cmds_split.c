/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:23:26 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 15:44:41 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	*free_cmds(char **cmds, int *i)
{
	int	index;

	index = 0;
	while (index < *i)
	{
		free(cmds[index]);
		index++;
	}
	free(cmds);
	return (NULL);
}

char	**cmds_split(char *cmd, char c)
{
	int		i;
	char	**cmds;

	i = 0;
	cmds = malloc((count_cmds(cmd, c) + 1) * sizeof(char *));
	if (!cmds)
		return (NULL);
	while (*cmd)
	{
		while (*cmd == c)
			cmd++;
		if (!*cmd)
		{
			free_array(cmds);
			exit(1);
		}
		cmds[i] = copy_cmd(cmd, c);
		if (!cmds[i])
			return (free_cmds(cmds, &i), NULL);
		cmd += get_cmd_len(cmd, c);
		i++;
	}
	cmds[i] = NULL;
	trim_cmds(cmds);
	return (cmds);
}
