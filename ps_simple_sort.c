/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:21:27 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 14:21:49 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// push everything except 3 to b.
// small half goes to the bottom of b (rb), big half stays on top,
// so b is roughly pre-split and the insertion back into a is cheaper
static void	ps_push_to_b(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	half;

	size = ps_lstcount(*a);
	half = size / 2;
	while (size > 3)
	{
		ps_push_b(a, b, config);
		if ((*b)->rank < half && (*b)->next)
			ps_rotate_b(b, config);
		size--;
	}
}

// check every node of b, return the moves of the cheapest one to insert in a
static t_move	ps_cheapest(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	cur;
	int		i;
	int		size_a;
	int		size_b;

	size_a = ps_lstcount(a);
	size_b = ps_lstcount(b);
	best.cost = -1;
	i = 0;
	while (b)
	{
		cur = ps_best_move(ps_target_idx_a(a, b->rank), size_a, i, size_b);
		if (best.cost < 0 || cur.cost < best.cost)
			best = cur;
		i++;
		b = b->next;
	}
	return (best);
}

void	ps_simple_sort(t_stack **a, t_stack **b, t_config *config)
{
	t_move	m;

	ps_init_rank(*a);
	if (ps_is_sorted(*a))
		return ;
	if (ps_lstcount(*a) <= 3)
	{
		ps_sort_small(a, config);
		return ;
	}
	ps_push_to_b(a, b, config);
	ps_sort_small(a, config);
	while (*b)
	{
		m = ps_cheapest(*a, *b);
		ps_exec_move(&m, a, b, config);
		ps_push_a(a, b, config);
	}
	ps_rot_a(ps_signed_moves_to_top(ps_min_idx(*a), ps_lstcount(*a)),
		a, config);
}
