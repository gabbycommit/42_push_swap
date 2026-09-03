/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:34:30 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 15:38:46 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Adds the node ’new’ at the end of the list.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node -> next = new;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*curr;

	printf("--- Test: Adding new to empty list ---\n");
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew("node1");
	ft_lstadd_back(&head, node1);
	curr = head;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}

	printf("\n--- Test: Adding new to existing list ---\n");
	t_list	*node2 = ft_lstnew("node2");
	ft_lstadd_back(&head, node2);
	curr = head;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}
	free(node1);
	free(node2);
	return (0);
}
*/
