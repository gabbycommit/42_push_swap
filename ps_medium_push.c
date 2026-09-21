/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:48:37 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/21 12:47:55 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// position of the closest node (from top or bottom) with rank < limit
static int	ps_find_cheapest_node_idx(t_stack *a, int limit, int n)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = -1;
	last = -1;
	while (a)
	{
		if (a->rank < limit)
		{
			if (first == -1)
				first = i;
			last = i;
		}
		a = a->next;
		i++;
	}
	if (first <= n - last)
		return (first);
	return (last);
}

static void	ps_flush_rb(t_chunk *c, t_stack **b, t_config *config)
{
	if (c->pending_to_rb)
		ps_rotate_b(b, config, 1);
	c->pending_to_rb = 0;
}

static void	ps_bring_to_top(
				t_chunk *c, t_stack **a, t_stack **b, t_config *config)
{
	int	n;
	int	cheapest_node_idx;
	int	limit;

	n = (int)ps_lstcount(*a);
	limit = c->pushed + c->size;
	cheapest_node_idx = ps_find_cheapest_node_idx(*a, limit, n);
	if (cheapest_node_idx > 0
		&& cheapest_node_idx <= n / 2
		&& c->pending_to_rb)
	{
		ps_rr(a, b, config);
		c->pending_to_rb = 0;
		cheapest_node_idx--;
	}
	ps_flush_rb(c, b, config);
	ps_rot_a_dir(cheapest_node_idx, n, a, config);
}

// sliding window: only nodes with rank < pushed + chunk are pushed to b
// nodes with a small rank (rank < pushed) sink to the bottom of b
void	ps_push_chunks(t_stack **a, t_stack **b, t_config *config, int n)
{
	t_chunk	c;
	int		rank;

	c.size = ps_chunk_size(n);
	c.pushed = 0;
	c.pending_to_rb = 0;
	while (*a)
	{
		ps_bring_to_top(&c, a, b, config);
		rank = (*a)->rank;
		ps_push_b(a, b, config);
		if (rank < c.pushed)
			c.pending_to_rb = 1;
		c.pushed++;
	}
}
