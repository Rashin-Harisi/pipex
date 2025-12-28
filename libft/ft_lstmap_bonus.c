/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:30:56 by rabdolho          #+#    #+#             */
/*   Updated: 2025/10/13 09:31:06 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*cleanup_handler(t_list **new_list_head, void (*del)(void *),
		void *new_content)
{
	if (new_content != NULL)
		del(new_content);
	ft_lstclear(new_list_head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f ||!del)
		return (NULL);
	new_list_head = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		if (new_content == NULL)
			return (cleanup_handler(&new_list_head, del, new_content));
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
			return (cleanup_handler(&new_list_head, del, new_content));
		ft_lstadd_back(&new_list_head, new_node);
		lst = lst->next;
	}
	return (new_list_head);
}
