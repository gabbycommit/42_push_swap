/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:11:47 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/30 18:06:54 by hukhaw           ###   ########.fr       */
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
