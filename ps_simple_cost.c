/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 11:52:01 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 18:12:31 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// idx -> signed number of moves to bring that index to the top
// >= 0 : rotate (ra / rb) this many times
// <  0 : reverse rotate (rra / rrb) -n times
int	ps_signed_moves_to_top(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	return (idx - size);
}

// cost of doing a-moves and b-moves together
// same direction -> shared with rr / rrr, so only the larger one counts
// opposite direction -> nothing shared, so add both
int	ps_total_cost(int a, int b)
{
	if (a <= 0 && b <= 0)
	{
		a = -a;
		b = -b;
	}
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0)
		return (b - a);
	return (a - b);
}

// index of the smallest rank in the list
int	ps_min_idx(t_stack *lst)
{
	int	i;
	int	idx;
	int	min;

	i = 0;
	idx = 0;
	min = lst->rank;
	while (lst)
	{
		if (lst->rank < min)
		{
			min = lst->rank;
			idx = i;
		}
		i++;
		lst = lst->next;
	}
	return (idx);
}

// index in a of the node that "rank" should sit on top of:
// the smallest rank bigger than "rank", or the min of a if none
int	ps_target_idx_a(t_stack *a, int rank)
{
	t_stack	*cur;
	int		i;
	int		idx;
	int		best;

	cur = a;
	i = 0;
	idx = -1;
	best = INT_MAX;
	while (cur)
	{
		if (cur->rank > rank && cur->rank < best)
		{
			best = cur->rank;
			idx = i;
		}
		i++;
		cur = cur->next;
	}
	if (idx < 0)
		return (ps_min_idx(a));
	return (idx);
}
