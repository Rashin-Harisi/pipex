/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:41:45 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/14 14:08:54 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

int	count_substring_handler(char const *s, char c)
{
	unsigned int	index;
	unsigned int	count;

	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			break ;
		count++;
		while (s[index] != c && s[index] != '\0')
			index++;
	}
	return (count);
}

int	len_substring_handler(char const *s, char c, unsigned int *index)
{
	unsigned int	len;

	len = 0;
	while (s[*index] != c && s[*index] != '\0')
	{
		(*index)++;
		len++;
	}
	return (len);
}

void	*free_handler(char **ptr, unsigned int *i_ptr)
{
	unsigned int	index;

	index = 0;
	while (index < *i_ptr)
	{
		free(ptr[index]);
		index++;
	}
	free(ptr);
	return (NULL);
}

char	*copy_handler( unsigned int *index, char const *s, char c)
{
	unsigned int	i_start;
	unsigned int	i;
	char			*word;
	unsigned int	len;

	i = 0;
	i_start = *index;
	len = len_substring_handler(s, c, index);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	if (len > 0)
	{
		while (i < len)
		{
			word[i] = s[i_start + i];
			i++;
		}
		word[len] = '\0';
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;
	unsigned int	index;
	unsigned int	i_ptr;

	index = 0;
	i_ptr = 0;
	ptr = malloc ((count_substring_handler(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			break ;
		ptr[i_ptr] = copy_handler(&index, s, c);
		if (ptr[i_ptr] == NULL)
			free_handler(ptr, &i_ptr);
		i_ptr++;
	}
	ptr[i_ptr] = NULL;
	return (ptr);
}

/*
int main()
{
	char test[]= "     ";
	char **result = ft_split(test, ' ');
    unsigned int i = 0;
    while(result[i] != NULL){
        printf("the index %d is %s.\n", i , result[i]);
        i++;
    }
    i = 0;
    while(result[i] != NULL){
        free(result[i]);
        i++;
    }
    free(result);
    printf("memory is freed now.\n");
    return 0;
}*/
