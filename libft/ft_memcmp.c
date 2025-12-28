/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:33:33 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:33:46 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	unsigned int	index;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (p_s1[index] == p_s2[index])
			index++;
		else
			return (p_s1[index] - p_s2[index]);
	}
	return (0);
}

/*
int main(){
    char s1[] = "ABCD";
    char s2[] = "ABCE";
    int result1;
    int result2;

    result1 = ft_memcmp(s1,s2,3);
    result2 = memcmp(s1,s2,3);

    printf("my function:");
    if(result1 > 0) printf("%s greater than %s\n", s1,s2);
    else if(result1 < 0) printf("%s smaller than %s\n", s1,s2);
    else printf("%s equal to %s\n", s1,s2);

    printf("origin function:");
    if(result2 > 0) printf("%s greater than %s\n", s1,s2);
    else if(result2 < 0) printf("%s smaller than %s\n", s1,s2);
    else printf("%s equal to %s\n", s1,s2);


    return 0;
}*/
