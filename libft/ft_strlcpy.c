/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:47:46 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:48:13 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <string.h>
//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[j] && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

/*
int main(){
    int result;
    char str[]= "Hello world!";
    char dest[10];
    result = ft_strlcpy(dest,str,sizeof(dest));
    printf("copied string is : %s\n", dest);
    if(result >= sizeof(dest)) {
        printf("the string is truncated!\n");
        return 1;
    };
    return 0;
}*/
