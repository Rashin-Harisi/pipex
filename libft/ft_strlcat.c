/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:46:58 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:47:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>
/*
the behavior if this function is : at the end it returns sum length of
src and dest. but beside that concating action will take place,
and at first it make sure that 
anything is in the dest buffer and then if it still has the space concat 
the src string to it. 
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	src_length;
	unsigned int	dest_length;

	a = 0;
	dest_length = 0;
	src_length = ft_strlen(src);
	while (dest[dest_length] != '\0' && dest_length < size)
		dest_length++;
	if (dest_length == size)
		return (src_length + dest_length);
	while (a < (size - dest_length - 1) && src[a] != '\0')
	{
		dest[dest_length + a] = src[a];
		a++;
	}
	if (a + dest_length < size)
		dest[a + dest_length] = '\0';
	return (src_length + dest_length);
}

/*
int main(){
    char test1[10] = "Hello";
    char test2[10] = "world";
    int length;
    length = ft_strlcat(test1,test2,sizeof(test1));
    printf("the result of origin function is : %d\n", length);
    printf("test1 after : %s\n", test1);
    printf("test2 after : %s\n", test2);
    printf("the buffer is %lu and charachters %d.\n", sizeof(test1), length);
    return 0;
}
*/
