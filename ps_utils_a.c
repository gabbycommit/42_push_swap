/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:11:47 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 09:57:06 by hukhaw           ###   ########.fr       */
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

// adding new node to stack at back
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

// create new counter struct
t_counter	*ps_new_counter(void)
{
	t_counter	*new_counter;

	new_counter = (t_counter *)malloc(sizeof(t_counter));
	if (!new_counter)
		return (NULL);
	new_counter->sa = 0;
	new_counter->sb = 0;
	new_counter->ss = 0;
	new_counter->pa = 0;
	new_counter->pb = 0;
	new_counter->ra = 0;
	new_counter->rb = 0;
	new_counter->rra = 0;
	new_counter->rrb = 0;
	return (new_counter);
}
