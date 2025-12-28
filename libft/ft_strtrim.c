/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:56:14 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:57:09 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

int	index_start_handler(char const *s1, char const *set)
{
	unsigned int	set_i;
	int				flag;
	unsigned int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		set_i = 0;
		flag = 0;
		while (set[set_i] != '\0')
		{
			if (s1[index] == set[set_i])
				flag = 1;
			set_i++;
		}
		if (flag == 0)
			return (index);
		index++;
	}
	return (index);
}

int	index_end_handler(char const *s1, char const *set)
{
	unsigned int	set_i;
	int				flag;
	unsigned int	index;

	index = ft_strlen(s1) - 1;
	while (1)
	{
		set_i = 0;
		flag = 0;
		while (set[set_i] != '\0')
		{
			if (s1[index] == set[set_i])
				flag = 1;
			set_i++;
		}
		if (flag == 0 || index == 0)
			return (index);
		index--;
	}
}

void	copy_trim_handler(char const *s1, unsigned int *start,
		unsigned int *end, void *ptr)
{
	unsigned int	p_index;

	p_index = 0;
	while (*start <= *end)
	{
		((unsigned char *)ptr)[p_index] = s1[*start];
		(*start)++;
		p_index++;
	}
	((unsigned char *)ptr)[p_index] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	end;
	unsigned int	start;
	void			*ptr;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	start = index_start_handler(s1, set);
	end = index_end_handler(s1, set);
	if (end < start)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		((unsigned char *)ptr)[0] = '\0';
		return (ptr);
	}
	ptr = malloc((end - start + 2) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	copy_trim_handler(s1, &start, &end, ptr);
	return (ptr);
}

/*
int main(){
    char test[] = "xxnxcdfr";
    char set[] = "x";
    char *result = ft_strtrim(test,set);
    if(result == NULL) printf("memory allocation failed.");
    else printf("the result is : %s\n", result);
    free(result);
    return 0;
}*/
