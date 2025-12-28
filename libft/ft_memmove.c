/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:34:47 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:35:30 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char unsigned	*p_dest;
	char unsigned	*p_src;
	size_t			i;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest < p_src)
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	if (p_dest > p_src)
	{
		i = n;
		while (i > 0)
		{
			p_dest[i - 1] = p_src[i - 1];
			i--;
		}
	}
	return (dest);
}

/*
int main(){
    char str1[]= "123456789";
    char str2[]= "123456789";

    memmove(str2+2, str2,4);
    ft_memmove(str1+2, str1,4);

    printf("the oringin function %s.\n", str2);
    printf("my function %s.\n", str1);

    return 0;
}*/
