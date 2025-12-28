/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:16:13 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:23:10 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)str;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

/*
int main()
{
    char str1[] = "Hello world!";
    char str2[] = "Hello world!";
    bzero(str1 + 6, 3);
    ft_bzero(str2 + 6 , 3);

    printf("test the origin function: %s\n",str1 );
    printf("test my function: %s\n", str2);
    return 0;
}*/
