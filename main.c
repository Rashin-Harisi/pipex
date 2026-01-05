/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/05 12:02:23 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (argc < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40));
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (argc < 6)
			return (write(2, "Not enough data\n", 16));
		return (append(argc, argv, envp));
	}
	else
		return (multipipex(argc, argv, envp));
	return (0);
}
