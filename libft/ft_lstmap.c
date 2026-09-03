/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:53:45 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 12:32:02 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Iterates through the list ’lst’, applies the
 *		function ’f’ to each node’s content, and creates
 *		a new list resulting of the successive applications
 *		of the function ’f’. The ’del’ function is used to
 *		delete the content of a node if needed.
 *
 *	RETURN:
 *		The new list.
 *		NULL if the allocation fails.
 */

t_list	*ft_lstmap(
	t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*curr;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	head = NULL;
	while (curr)
	{
		new_node = ft_lstnew(f(curr -> content));
		if (!new_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		curr = curr -> next;
	}
	return (head);
}

/*
#include <stdio.h>

void	*test_function(void *content)
{
	char	*result;
	char	*s;
	size_t	i;

	if (!content)
		return (NULL);
	s = (char *)content;
	result = (char *)malloc(sizeof(char ) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = ft_toupper(s[i]);
		i++;
	}
	result[i] = '\0';
	return ((void *)result);
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
	t_list	*result;
	t_list	*curr;

	node1 -> next = node2;
	node2 -> next = node3;
	printf("Original:\n");
	curr = node1;
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}

	result = ft_lstmap(node1, test_function, del);
	curr = result;
	printf("\nDispaly result of ft_lstmap:\n");
	while (curr)
	{
		printf("%s\n", (char *)curr -> content);
		curr = curr -> next;
	}
	printf("\nDeleting and free all content and node...\n");
	ft_lstclear(&result, del);
	ft_lstclear(&node1, del);
	return (0);
}
*/
