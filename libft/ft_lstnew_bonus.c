/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:31:25 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:31:37 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

/*
int main()
{
	char test[] = "welcom";
	t_list *result = ft_lstnew((void *)test);
	printf("%s\n", (char *)result->content);
	return 0;
}
*/
