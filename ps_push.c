/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:10:47 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 15:23:11 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_push_a(t_stack **a, t_stack **b, t_counter *count)
{
	t_stack	*first_b;
	t_stack	*second_b;

	if (!a || !b || !(*b))
		return ;
	first_b = *b;
	second_b = first_b->next;
	ps_lstadd_front(a, first_b);
	if (second_b)
	{
		second_b->prev = NULL;
		*b = second_b;
	}
	else
		*b = NULL;
	count->pa++;
	write(1, "pa", 2);
}

void	ps_push_b(t_stack **a, t_stack **b, t_counter *count)
{
	t_stack	*first_a;
	t_stack	*second_a;

	if (!a || !b || !(*a))
		return ;
	first_a = *a;
	second_a = first_a->next;
	ps_lstadd_front(b, first_a);
	if (second_a)
	{
		second_a->prev = NULL;
		*a = second_a;
	}
	else
		*a = NULL;
	count->pb++;
	write(1, "pb", 2);
}
