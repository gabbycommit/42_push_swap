/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:12:53 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 11:35:51 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Deletes and frees the given node and all its
 *		successors, using the function ’del’ and free(3).
 *		Finally, set the pointer to the list to NULL.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		del(curr -> content);
		temp = curr -> next;
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}

/*
#include <stdio.h>

void	del(void *content)
{
	if (!content)
		return ;
	printf("Deleting content: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("node1"));
	t_list	*node2 = ft_lstnew(ft_strdup("node2"));
	t_list	*node3 = ft_lstnew(ft_strdup("node3"));
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

	printf("\nClearing list...\n");
	curr = node1;
	ft_lstclear(&curr, del);
	printf("\nAfter: checking with Valgrind or fsanitize=address\n");
	return (0);
}
*/
