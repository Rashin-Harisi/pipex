/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:36:02 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:36:31 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = str;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*
int main()
{
    char str1[] = "Hello world!";
    char str2[] = "Hello world!";
    memset(str1 + 6, '*', 3);
    ft_memset(str2 + 6 , '*', 3);

    printf("test the origin function: %s\n",str1 );
    printf("test my function: %s\n", str2);
    return 0;
}*/
