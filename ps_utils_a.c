/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:11:47 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/09 11:32:42 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// create new node for stack a
t_stack	*ps_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

// get the last node of stack
t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// adding new node to stack back
void	ps_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last_node;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	last_node = ps_lstlast(*lst);
	last_node->next = new_node;
	new_node->prev = last_node;
}

// adding new node to stack front
void	ps_lstadd_front(t_stack **lst, t_stack *new_node)
{
	t_stack	*second;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	second = (*lst)->next;
	new_node->prev = NULL;
	new_node->next = *lst;
	(*lst)->prev = new_node;
	if (second)
	{
		(*lst)->next = second;
		second->prev = *lst;
	}
	else
		(*lst)->next = NULL;
	*lst = new_node;
}

size_t	ps_lstcount(t_stack *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
