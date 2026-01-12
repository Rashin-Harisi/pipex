/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_cmds_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:23:26 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/12 15:56:00 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	skip_word(int *i, char *cmd, char c)
{
	int	q;

	q = 0;
	while (cmd[*i] && (cmd[*i] != c || q))
	{
		if (cmd[*i] == '\\' && cmd[(*i) + 1])
			(*i) += 2;
		else
		{
			if ((cmd[*i] == '\'' || cmd[*i] == '\"') && !q)
				q = cmd[*i];
			else if (q && cmd[*i] == q)
				q = 0;
			(*i)++;
		}
	}
}

int	count_cmds(char	*cmd, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		while (cmd[i] == c)
			i++;
		if (!cmd[i])
			break ;
		count++;
		skip_word(&i, cmd, c);
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
		if (cmd[i] == '\\' && cmd[i + 1])
			i += 2;
		else
		{
			if ((cmd[i] == '\'' || cmd[i] == '\"') && !q)
				q = cmd[i];
			else if (cmd[i] == q)
				q = 0;
			i++;
		}
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
