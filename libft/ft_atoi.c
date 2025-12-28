/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:15:36 by rabdolho          #+#    #+#             */
/*   Updated: 2025/12/26 10:19:34 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

int	check_handler(const char *str, int *i, int *sign)
{
	if (!(str[*i + 1] >= '0' && str[*i + 1] <= '9'))
		return (0);
	else
	{
		if (str[*i] == '+')
			(*i)++;
		if (str[*i] == '-')
		{
			*sign = *sign * -1;
			(*i)++;
		}
	}
	return (*sign);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		check_handler(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/*
int main(void)
{
    char str[] = "   -12457abc";
    printf("the origin function : %d\n", atoi(str));
    printf("my function : %d\n", ft_atoi(str));
    return 0;
}*/
