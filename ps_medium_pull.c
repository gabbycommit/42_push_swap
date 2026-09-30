/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_pull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:39:48 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 14:48:42 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_find_target_idx(t_stack *b, int rank)
{
	int	i;

	i = 0;
	while (b && b->rank != rank)
	{
		b = b->next;
		i++;
	}
	return (i);
}

static int	ps_bottom_rank(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->rank);
}

// push top of b to a and send it to the bottom of a.
// if b also needs an rb to reach next, do both at once with rr
static void	ps_park(t_stack **a, t_stack **b, t_config *config, int next)
{
	int	idx;

	ps_push_a(a, b, config);
	idx = ps_find_target_idx(*b, next);
	if (idx > 0 && idx <= (int)ps_lstcount(*b) / 2)
		ps_rr(a, b, config);
	else
		ps_rotate_a(a, config);
}

// parked nodes sit at the bottom of a, growing toward the bottom.
// top of b can be parked if it is bigger than the current bottom parked node
static void	ps_park_or_rotate(
				t_stack **a, t_stack **b, t_config *config, int next)
{
	int	bottom;
	int	size;

	bottom = -1;
	if (*a && ps_bottom_rank(*a) < next)
		bottom = ps_bottom_rank(*a);
	size = (int)ps_lstcount(*b);
	if ((*b)->rank > bottom)
		ps_park(a, b, config, next);
	else if (ps_find_target_idx(*b, next) <= size / 2)
		ps_rotate_b(b, config);
	else
		ps_reverse_rotate_b(b, config);
}

// next = rank that must go on top of a next.
// it is either at the bottom of a (parked) or somewhere in b.
// while rotating b to reach it, useful nodes get parked instead of skipped
void	ps_pull_back(t_stack **a, t_stack **b, t_config *config)
{
	int	next;

	next = (int)ps_lstcount(*b) - 1;
	while (next >= 0)
	{
		if (*a && ps_bottom_rank(*a) == next)
			ps_reverse_rotate_a(a, config);
		else if ((*b)->rank == next)
			ps_push_a(a, b, config);
		else
			ps_park_or_rotate(a, b, config, next);
		if (*a && (*a)->rank == next)
			next--;
	}
}
