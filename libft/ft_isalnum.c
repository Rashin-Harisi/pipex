/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:17:49 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:22:20 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isalnum(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
int main (int argc, char *argv[]) {

    int result;
    if(argc < 2) printf("There is not enough input.");
    result = ft_isalnum(*argv[1]);
    //result = isalnum(*argv[1]);
    if(result != 0) printf("The charcter is alphanumeric");
    else printf("The character is not alphanumeric");
    return 0;
}*/
