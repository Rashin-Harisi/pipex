/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:32:20 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 11:01:43 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p_s;
	int				flag;
	unsigned char	*ptr;

	i = 0;
	p_s = (unsigned char *)s;
	flag = 0;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
		{
			ptr = &p_s[i];
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (ptr);
	else
		return (NULL);
}

/*
int main(){
    char test[] = "/|\x12\xff\x09\x42\2002\42|\\";
    char *ptr1 = memchr(test,'\200',10);
    char *ptr2 = ft_memchr(test, '\200', 10);
    write(1,test,strlen(ptr1));
    printf("\n");
    //printf("origin function : %s\n",ptr1);
    //else printf("nothing match!\n");
    write(1,test,strlen(ptr2));
    printf("\n");
    //printf("my function : %s\n", ptr2);
    //else printf("nothing match!\n");

    return 0;
}*/
