/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:53:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/30 20:45:11 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int main(int argc, char *argv[],char **envp)
{
	if (argc < 5)
		return (write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40));
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (argc < 6)
			return (write(2, "Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 50));
		append(argc, argv, envp);
	}
	else
		multipipex(argc, argv, envp);
	return (0);
}
