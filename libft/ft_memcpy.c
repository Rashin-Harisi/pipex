/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:34:08 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:34:28 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//#include <string.h>
//#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	p_dest = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (p_dest);
}

/*
int main(){
    
    char str1[] = "Hello world!";
    char str2[] = "Hello world!";
    char dest1[20];
    char dest2[20];
    ft_memcpy(dest1, str1 ,4);
    dest1[4] = '\0';
    memcpy(dest2, str2,4);
    printf("the origin function: %s\n", dest2);
    printf("my function : %s\n", dest1);
    
    //char str1[]= "123456789";
    //char str2[]= "123456789";
    //ft_memcpy(str1+2, str1,4);
    //memcpy(str2+2, str2,4);
    //printf("the origin function: %s\n", str2);
    //printf("my function : %s\n", str1);
    
    return 0;
}*/
