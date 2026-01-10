/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:23:26 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/10 17:35:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	count_cmds(char	*cmd, char c)
{
	int	i;
	int	q;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		while (cmd[i] == c)
			i++;
		if (cmd[i])
			count++;
		q = 0;
		while (cmd[i] && (cmd[i] != c || q))
		{
			if ((cmd[i] == '\'' || cmd[i] == '\"') && !q)
				q = cmd[i];
			else if (cmd[i] == q)
				q = 0;
			i++;
		}
	}
	return (count);
}

int	get_cmd_len(char *cmd, char c)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (cmd[i] && (cmd[i] != c || q))
	{
		if ((cmd[i] == '\'' || cmd[i] == '\"') && !q)
			q = cmd[i];
		else if (cmd[i] == q)
			q = 0;
		i++;
	}
	return (i);
}

char	*copy_cmd(char *cmd, char c)
{
	int		len;
	int		i;
	char	*new;

	len = get_cmd_len(cmd, c);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = cmd[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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
	int		cmd_leng;

	i = 0;
	cmds = malloc((count_cmds(cmd, c) + 1) * sizeof(char *));
	if (!cmds)
		return (NULL);
	while (*cmd)
	{
		while (*cmd == c)
			cmd++;
		if (!*cmd)
			break ;
		cmds[i] = copy_cmd(cmd, c);
		if (!cmds[i])
			return (free_cmds(cmds, &i), NULL);
		cmd_leng = get_cmd_len(cmd, c);
		cmd += cmd_leng;
		if (!*cmd)
			break ;
		i++;
	}
	cmds[i] = NULL;
	trim_cmds(cmds);
	return (cmds);
}
