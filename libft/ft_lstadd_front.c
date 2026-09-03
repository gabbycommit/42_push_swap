/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:50:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 22:35:51 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	DESCRIPTION:
 *		Adds the node ’new’ at the beginning of the list.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*curr;

	printf("--- Test: Adding to an empty list---\n");
	t_list	*node1 = ft_lstnew("Node 1");
	t_list	*head = NULL;
	ft_lstadd_front(&head, node1);
	curr = head;
	while (curr)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr -> next;
	}

	printf("\n--- Test: Adding to an existing list ---\n");
	t_list	*new_node = ft_lstnew("new node");
	ft_lstadd_front(&head, new_node);
	curr = head;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}
	free(node1);
	free(new_node);
	return (0);
}
*/
