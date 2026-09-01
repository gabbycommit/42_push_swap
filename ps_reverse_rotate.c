/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:31:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 15:59:43 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// [first]->[]->[prev_last]->[last]

void	ps_reverse_rotate_a(t_stack **a, t_counter *count, int is_write)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev_last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (ps_lstcount(*a) == 2)
		ps_swap_a(a, count, 0);
	else
	{
		first = *a;
		last = ps_lstlast(*a);
		prev_last = last->prev;
	}
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	prev_last->next = NULL;
	*a = last;
	if (is_write)
	{
		count->rra++;
		write(1, "rra", 3);
	}
}

void	ps_reverse_rotate_b(t_stack **b, t_counter *count, int is_write)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev_last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	if (ps_lstcount(*b) == 2)
		ps_swap_b(b, count, 0);
	else
	{
		first = *b;
		last = ps_lstlast(*b);
		prev_last = last->prev;
	}
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	prev_last->next = NULL;
	*b = last;
	if (is_write)
	{
		count->rrb++;
		write(1, "rrb", 3);
	}
}

void	ps_rrr(t_stack **a, t_stack **b, t_counter *count)
{
	ps_reverse_rotate_a(a, count, 0);
	ps_reverse_rotate_b(b, count, 0);
	count->rrr++;
	write(1, "rrr", 3);
}
