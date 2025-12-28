/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:18:54 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:20:50 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int main (int argc, char *argv[]) {

    int result;
    if(argc < 2) 
    {
        printf("There is not enough input.");
        return 1;
    }
    printf("test %d\n", atoi(argv[1]));
    result = ft_isascii(atoi(argv[1]));
    //result = isascii(atoi(argv[1]));
    if(result != 0) printf("The charcter is in ascii range.");
    else printf("The character is not in ascii range");
    return 0;
}*/
