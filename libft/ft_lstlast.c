/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:07:32 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 10:14:13 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Returns the last node of the list.
 *
 * 	RETURN:
 * 		Last node of the list.
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr -> next)
		curr = curr -> next;
	return (curr);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");
	t_list	*node3 = ft_lstnew("node3");
	t_list	*last;

	node1 -> next = node2;
	node2 -> next = node3;
	last = ft_lstlast(node1);
	printf("%s\n", (char *)last -> content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
