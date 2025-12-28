/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:58:08 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:58:39 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}

/*
int main()
{
    char test[15] = "HelLo WorlD!";
    printf("The original function: ");
    for(int i = 0 ; i < 15; i++)
    {
        printf("%c", tolower(test[i]));
    }
    printf("\n");
    printf("My function: ");
    for(int i = 0 ; i < 15; i++)
    {
        printf("%c",ft_tolower(test[i]));
    }
    printf("\n");
    return 0;
}*/
