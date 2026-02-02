/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_third.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/13 11:01:25 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
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
		//paths = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", ':');
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

char	*copy_trim_helper(char *new, int *i, char *str, size_t len)
{
	int		j;

	j = 0;
	while (*i < (int)len)
	{
		if (str[*i] == '\\' && str[(*i) + 1])
			(*i)++;
		new[j++] = str[(*i)++];
	}
	new[j] = '\0';
	return (new);
}

char	*trim_helper(char *str)
{
	size_t	len;
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (str);
	if (len >= 2 && ((str[0] == '\'' || str[0] == '\"')
			&& str[len - 1] == str[0]))
	{
		i = 1;
		len = len - 1;
	}
	copy_trim_helper(new, &i, str, len);
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
		cmds[i] = trim_helper(cmds[i]);
		if (!cmds[i])
		{
			free_array(cmds);
			exit(0);
		}
		i++;
	}
}
