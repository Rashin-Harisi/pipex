/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:14:16 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:46:27 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static void	count_handler(size_t *count, unsigned int number)
{
	while (number != 0)
	{
		number = number / 10;
		(*count)++;
	}
}

static void	ptr_handler(char *ptr, unsigned int n,
		size_t *count)
{
	ptr[*count] = '\0';
	(*count)--;
	while (n != 0)
	{
		ptr[*count] = (n % 10) + '0';
		n = n / 10 ;
		(*count)--;
	}
}

char	*ft_utoa(unsigned int n)
{
	size_t			count;
	char			*ptr;

	count = 0;
	if (n == 0)
	{
		ptr = malloc((2) * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	count_handler(&count, n);
	ptr = malloc((count + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr_handler(ptr, n, &count);
	return (ptr);
}
