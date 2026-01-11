/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2026/01/11 14:37:47 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		ft_putstr_fd("OR: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (argc < 6)
		{
			ft_putstr_fd("Error: Not enough arguments for here_code\n", 2);
			return (1);
		}
		return (append(argc, argv, envp));
	}
	return (multipipex(argc, argv, envp));
}
