/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:58:55 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:59:15 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
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
        printf("%c", toupper(test[i]));
    }
    printf("\n");
    printf("My function: ");
    for(int i = 0 ; i < 15; i++)
    {
        printf("%c",ft_toupper(test[i]));
    }
    printf("\n");
    return 0;
}
*/
