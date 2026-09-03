/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:52:37 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 11:12:33 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Takes a node as parameter and frees its content
 *		using the function ’del’. Free the node itself but
 *		does NOT free the next node.
 */	

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

/*
#include <stdio.h>

void	del(void *content)
{
	if (!content)
		return ;
	free(content);
}

int	main(void)
{
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew(ft_strdup("node2"));
	t_list	*node3 = ft_lstnew("node3");
	t_list	*curr;

	node1 -> next = node2;
	node2 -> next = node3;
	
	printf("Original list:\n");
	curr = node1;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}

	printf("\nDeleting node2...\n");
	ft_lstdelone(node2, del);
	node1 -> next = node3;

	printf("\nAfter:\n");
	curr = node1;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}
	free(node1);
	free(node3);
	return (0);
}
*/
