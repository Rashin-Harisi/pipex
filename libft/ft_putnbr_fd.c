/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:38:50 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:40:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		nbr_chr;

	nbr = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (long)n * -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	nbr_chr = (nbr % 10) + '0';
	write(fd, &nbr_chr, 1);
}

/*
int main(){
    int n = -2147483648;
    //write(1,&n,3);
    ft_putnbr_fd(n,1);
    printf("\n");
    return 0;
}*/
