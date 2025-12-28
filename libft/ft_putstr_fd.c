/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:41:06 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:41:11 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}

/*
int main(){
    char test[] = "Hello world";
    ft_putstr_fd(test,1);
    ft_putstr_fd(test,2);
    return 0;
}*/
