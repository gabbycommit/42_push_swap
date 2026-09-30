/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_quick_sort_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:25:32 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 11:56:17 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ps_in_a(t_loc loc)
{
	return (loc == TOP_A || loc == BOTTOM_A);
}

/* rank of the element that would be taken next from this location */
int	ps_peek(t_ps *ps, t_loc loc)
{
	t_stack	*stack;

	if (ps_in_a(loc))
		stack = *ps->a;
	else
		stack = *ps->b;
	if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (stack->next)
			stack = stack->next;
	return (stack->rank);
}

/* move one element from one of the 4 locations to another */
void	ps_move(t_ps *ps, t_loc from, t_loc to)
{
	if (from == BOTTOM_A)
		ps_reverse_rotate_a(ps->a, ps->config);
	else if (from == BOTTOM_B)
		ps_reverse_rotate_b(ps->b, ps->config);
	if (ps_in_a(from) && !ps_in_a(to))
		ps_push_b(ps->a, ps->b, ps->config);
	else if (!ps_in_a(from) && ps_in_a(to))
		ps_push_a(ps->a, ps->b, ps->config);
	if (to == BOTTOM_A)
		ps_rotate_a(ps->a, ps->config);
	else if (to == BOTTOM_B)
		ps_rotate_b(ps->b, ps->config);
}
