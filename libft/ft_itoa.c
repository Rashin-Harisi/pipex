/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:25:53 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:26:35 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
/*#include <stdtio.h>
#include <limits.h>*/

int	sign_count_handler(size_t *count, int *signe, int n)
{
	int	number;

	number = n;
	if (number < 0)
	{
		*signe = -(*signe);
		(*count)++;
		n = -n;
	}
	while (number != 0)
	{
		number = number / 10;
		(*count)++;
	}
	return (n);
}

void	ptr_handler(char *ptr, unsigned int *dividend,
		size_t *count, int *signe)
{
	if (*signe == -1)
		ptr[0] = '-';
	ptr[*count] = '\0';
	(*count)--;
	while (*dividend != 0)
	{
		ptr[*count] = (*dividend % 10) + '0';
		*dividend = *dividend / 10 ;
		(*count)--;
	}
}

char	*ft_itoa(int n)
{
	size_t			count;
	int				signe;
	char			*ptr;
	unsigned int	dividend;

	count = 0;
	signe = 1;
	if (n == 0)
	{
		ptr = malloc((2) * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	dividend = sign_count_handler(&count, &signe, n);
	ptr = malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr_handler(ptr, &dividend, &count, &signe);
	return (ptr);
}

/*
int main(){
    int test = -2147483648;
    int test2 = 2147483647;
    char *result = ft_itoa(test);
    char *result2 = ft_itoa(test2);
    printf("the sring format of %d number is : '%s' \n",test,result);
    printf("the sring format of %d number is : '%s' \n",test2,result2);
    free(result);
    free(result2);
    printf("memory is freed now\n");
    return 0;
}*/
