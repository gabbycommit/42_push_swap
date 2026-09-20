/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 11:33:15 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/20 11:48:51 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

// moves needed on b so that the node "rank" should sit on top of
// (its target: biggest smaller one, or the max of b if none) reaches the top
static int	ps_b_moves(t_stack *b, int size_b, int rank)
{
	int	idx;

	if (size_b == 0)
		return (0);
	idx = ps_target_idx_b(b, rank);
	if (idx < 0)
		idx = ps_max_idx(b);
	return (ps_signed_moves_to_top(idx, size_b));
}

// check every node of a, return the moves of the cheapest one
static t_move	ps_cheapest(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	cur;
	int		i;
	int		size_a;
	int		size_b;

	size_a = (int)ps_lstcount(a);
	size_b = (int)ps_lstcount(b);
	best.a = 0;
	best.b = 0;
	best.cost = -1;
	i = 0;
	while (a)
	{
		cur.a = ps_signed_moves_to_top(i, size_a);
		cur.b = ps_b_moves(b, size_b, a->rank);
		cur.cost = ps_total_cost(cur.a, cur.b);
		if (best.cost < 0 || cur.cost < best.cost)
			best = cur;
		i++;
		a = a->next;
	}
	return (best);
}

// b is kept in descending (circular) order, so the biggest must be on top
// before pushing everything back to a
static void	ps_b_max_to_top(t_stack **b, t_config *config)
{
	if (!*b)
		return ;
	ps_rot_b(
		ps_signed_moves_to_top(ps_max_idx(*b), (int)ps_lstcount(*b)),
		b,
		config);
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
	while (*a)
	{
		m = ps_cheapest(*a, *b);
		ps_exec_move(&m, a, b, config);
		ps_push_b(a, b, config);
	}
	ps_b_max_to_top(b, config);
	while (*b)
		ps_push_a(a, b, config);
}
