/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:17:11 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:17:25 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	total_memory;
	unsigned int	index;

	if (size == 0 || nmemb == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		((unsigned char *)ptr)[0] = 0;
		return (ptr);
	}
	total_memory = nmemb * size;
	ptr = malloc(total_memory);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (index < total_memory)
	{
		((unsigned char *)ptr)[index] = 0;
		index++;
	}
	return (ptr);
}

/*
int main(){
    char *ptr_test1 = calloc(5,sizeof(char));
    printf("the origin function: ");
    for(int i =0; i<5; i++) printf("%d", ptr_test1[i]);
    printf("\n");

    char *ptr_test2 = ft_calloc(5,sizeof(char));
    printf("my function: ");
    for(int i =0; i<5; i++) printf("%d", ptr_test2[i]);
    printf("\n");

    free(ptr_test1);
    free(ptr_test2);
    printf("memory is free now.\n");

    return 0;
}*/
