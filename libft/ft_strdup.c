/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:44:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:45:14 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <string.h>
//#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	unsigned int	length;
	void			*ptr;
	unsigned int	index;
	unsigned char	*p;

	length = ft_strlen(s);
	index = 0;
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr != NULL)
	{
		p = (unsigned char *) ptr;
		while (s[index] != '\0')
		{
			p[index] = s[index];
			index++;
		}
		p[index] = '\0';
	}
	return (ptr);
}

/*
int main(){{
    char test[] = "hello world";

    char *new_memo = ft_strdup(test);
    char *new_memo2 = strdup(test);
    printf(" my function is:  %s\n", new_memo );
    printf("the origin function is:  %s\n", new_memo2 );

    free(new_memo);
    free(new_memo2);
    printf("memory is freed.");

    return 0;
}}
*/
