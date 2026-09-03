/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:36:51 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 11:52:36 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Iterates through the list ’lst’ and applies the
 *		function ’f’ to the content of each node.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr)
	{
		f(curr -> content);
		curr = curr -> next;
	}
}

/*
#include <stdio.h>

void	test_function(void *content)
{
	char	*s;
	size_t	i;

	if (!content)
		return ;
	s = (char *)content;
	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

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

	ft_lstiter(node1, test_function);
	printf("\nAfter list:\n");
	curr = node1;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}
	printf("\nDeleting all node...\n");
	ft_lstclear(&node1, del);
	return (0);
}
*/
