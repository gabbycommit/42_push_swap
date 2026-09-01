/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:30:23 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 15:23:37 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_rotate_a(t_stack **a, t_counter *count, int is_write)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (ps_lstcount(*a) == 2)
		ps_swap_a(a, count, 0);
	else
	{
		first = *a;
		second = first->next;
		last = ps_lstlast(*a);
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
	}
	*a = second;
	if (is_write)
	{
		count->ra++;
		write(1, "ra", 2);
	}
}

void	ps_rotate_b(t_stack **b, t_counter *count, int is_write)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	if (ps_lstcount(*b) == 2)
		ps_swap_b(b, count, 0);
	else
	{
		first = *b;
		second = first->next;
		last = ps_lstlast(*b);
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
	}
	*b = second;
	if (is_write)
	{
		count->rb++;
		write(1, "rb", 2);
	}
}

void	ps_rr(t_stack **a, t_stack **b, t_counter *count)
{
	ps_rotate_a(a, count, 0);
	ps_rotate_b(b, count, 0);
	count->rr++;
	write(1, "rr", 2);
}
