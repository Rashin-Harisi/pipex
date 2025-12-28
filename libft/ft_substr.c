/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:57:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/14 13:24:42 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void	*empty_handler(void)
{
	void	*ptr;

	ptr = malloc(1);
	if (ptr != NULL)
		((unsigned char *)ptr)[0] = '\0';
	return (ptr);
}

size_t	length_handler(char const *s, unsigned int start, size_t len)
{
	size_t	length;

	if (len + start > (unsigned int)ft_strlen(s))
		length = ft_strlen(s) - start;
	else
		length = len;
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void			*ptr;
	unsigned int	index_p;
	size_t			length;

	index_p = 0;
	if (len == 0 || start > (unsigned int)ft_strlen(s))
	{
		ptr = empty_handler();
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	length = length_handler(s, start, len);
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (index_p < length)
	{
		((unsigned char *)ptr)[index_p] = s[start];
		index_p++;
		start++;
	}
	((unsigned char *)ptr)[index_p] = '\0';
	return (ptr);
}

/*
int main(){
    char test[] = "tripouille";
    //for(int i = 0 ; i < 12 ; i++){
     //   printf("the index of %c is %d \n",test[i],i);
    //}
    char *result = ft_substr(test, 100,1);
	//	printf("%d\n", strcmp(result, ""));
    printf("the result is :%s\n",result);
    free(result);
    return 0;
}*/
