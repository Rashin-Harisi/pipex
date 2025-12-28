/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:49:53 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 15:36:11 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (index < n && s1[index] != '\0' && s2[index] != '\0'
		&& (s1[index] == s2[index]))
		index++;
	if (index == n)
		return (0);
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/*
int main()
{
    char s1[] = "abcdefgh";
    char s2[] = "abcdwxyz";
    int result1;
    int result2;

    result1 = ft_strncmp(s1,s2,4);
    result2 = strncmp(s1,s2,4);

    printf("my function: %d\n", ft_strncmp(s1,s2,4));
    //if(result1 > 0) printf("%s greater than %s\n", s1,s2);
    //else if(result1 < 0) printf("%s smaller than %s\n", s1,s2);
    //else printf("%s equal to %s\n", s1,s2);
    //printf("%d\n", ('c' - 'd'));
    printf("origin function: %d\n",strncmp(s1,s2,4));
    //if(result2 > 0) printf("%s greater than %s\n", s1,s2);
    //else if(result2 < 0) printf("%s smaller than %s\n", s1,s2);
    //else printf("%s equal to %s\n", s1,s2);


    return 0;
}*/
