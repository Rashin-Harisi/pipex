/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:46:19 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:46:37 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
//#include <stdio.h>
#include <stdlib.h>

void	copy_join_handler(char const *s, unsigned int *index_p, void *ptr)
{
	unsigned int	index;

	index = 0;
	while (s[index] != '\0')
	{
		((unsigned char *)ptr)[*index_p] = s[index];
		index++;
		(*index_p)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	length;
	void			*ptr;
	unsigned int	index_p;

	index_p = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	copy_join_handler(s1, &index_p, ptr);
	copy_join_handler(s2, &index_p, ptr);
	((unsigned char *)ptr)[index_p] = '\0';
	return (ptr);
}

/*
int main(){
    char s1[] = "Hello";
    char s2[] = " World";
    char *result = ft_strjoin(s1,s2);
    printf("the result is: %s\n", result);
    free(result);
    return 0;
}*/
