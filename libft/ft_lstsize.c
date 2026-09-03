/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 09:56:59 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 10:05:07 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Counts the number of nodes in the list.
 *
 * 	RETURN:
 * 		The length of the list
 */

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*curr;

	if (!lst)
		return (0);
	count = 0;
	curr = lst;
	while (curr)
	{
		count++;
		curr = curr -> next;
	}
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");
	t_list	*node3 = ft_lstnew("node3");

	node1 -> next = node2;
	node2 -> next = node3;
	unsigned int	size = ft_lstsize(node1);
	printf("%d\n", size);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
