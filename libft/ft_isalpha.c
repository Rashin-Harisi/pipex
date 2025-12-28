/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:18:19 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:21:40 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
int main (int argc, char *argv[]) {

    int result;
    if(argc < 2) printf("There is not enough input.");
    result = ft_isalpha(*argv[1]);
    //result = isalpha(*argv[1]);
    if(result != 0) printf("The charcter is alphabet");
    else printf("The character is not alphabet");
    return 0;
}*/
