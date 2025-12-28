/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:55:43 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 11:44:58 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*hex_convert_big(unsigned int nbr)
{
	char			*hex;
	char			*result;
	unsigned long	number;
	int				count;

	hex = "0123456789ABCDEF";
	number = nbr;
	count = 0;
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	if (nbr == 0)
		count++;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count] = '\0';
	while (count != 0)
	{
		result[--count] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	return (result);
}

char	*hex_convert_small(unsigned int nbr)
{
	char			*hex;
	char			*result;
	unsigned long	number;
	int				count;

	hex = "0123456789abcdef";
	number = nbr;
	count = 0;
	while (number != 0)
	{
		number = number / 16;
		count++;
	}
	if (nbr == 0)
		count++;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count] = '\0';
	while (count != 0)
	{
		result[--count] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	return (result);
}
