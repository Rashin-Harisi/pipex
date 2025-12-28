/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:28:10 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:28:29 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
	t_list *head = NULL;
	char test1[] = "First";
	char test2[] = "Second";

	t_list *node2 = ft_lstnew(test2);
	if(!node2) return 1;
	ft_lstadd_front(&head, node2);
	if(head == node2 && head->next == NULL)
	       printf("successful : %s\n",(char *)head->content);
	else printf("failure");

	t_list *node1 = ft_lstnew(test1);
	if(!node1) return 1;
	ft_lstadd_front(&head,node1);
	if(head == node1 && head->next == node2)
		printf("success: %s replaced the %s\n",
		(char *)head->content, (char *)head->next->content);
	else printf("failure");

	free(node1);
	free(node2);
	printf("memory is freed");
	return 0;
}*/
