/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:55:30 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 15:54:41 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int			flag;
	int			index;
	char		*ptr;

	flag = 0;
	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
		{
			flag = 1;
			ptr = (char *)&s[index];
			break ;
		}
		index--;
	}
	if (flag == 0 && index == 0)
		return (NULL);
	if (flag == 1)
		return (ptr);
	else
		return (NULL);
}

/*
int main(){
    char test[100] = "Hello world and welcome to my website";
    printf("Origin function: %s\n", strrchr(test, 'o'));
    printf("My function:  %s\n", ft_strrchr(test, 'o'));

    return 0;
}
*/
