/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:10:23 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 17:40:15 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Allocates memory (using malloc(3)) and returns
 *		a new node. The ’content’ member variable is
 *		initialized with the given parameter ’content’.
 *		The variable ’next’ is initialized to NULL.
 *
 *	RETURN:
 *		A pointer to the new node.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*new_node;

	new_node = ft_lstnew("hello");
	if (!new_node)
		return (1);
	printf("new node content: %s\n", (char *)new_node -> content);
	free(new_node);
	return (0);
}
*/
