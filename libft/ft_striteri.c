/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:45:47 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:46:02 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index ++;
	}
}

/*
void ft_upper(unsigned int index, char *c){
    (void)index;
    if(*c >= 97 && *c <= 122){
        *c -= 32;
    }
}

int main(){
    char test[]= "hello wWorld";
    unsigned int index = 0;
    ft_striteri(test,ft_upper);
    printf("the result is : %s\n", test);
    return 0;
}
*/
