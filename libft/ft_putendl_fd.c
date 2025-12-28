/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:38:10 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:38:23 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	index;
	char			new_line;

	new_line = '\n';
	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
	write(fd, &new_line, 1);
}

/*
int main(){
    char test[] = "Hello world";
    ft_putendl_fd(test,1);
    //ft_putendl_fd(test,2);
    return 0;
}*/
