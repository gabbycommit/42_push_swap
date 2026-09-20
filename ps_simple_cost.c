/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 11:52:01 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/20 11:52:06 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

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
int	ps_total_cost(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		if (ps_abs(a) > ps_abs(b))
			return (ps_abs(a));
		return (ps_abs(b));
	}
	return (ps_abs(a) + ps_abs(b));
}

// index of the biggest rank in the list
int	ps_max_idx(t_stack *lst)
{
	int	i;
	int	idx;
	int	max;

	i = 0;
	idx = 0;
	max = lst->rank;
	while (lst)
	{
		if (lst->rank > max)
		{
			max = lst->rank;
			idx = i;
		}
		i++;
		lst = lst->next;
	}
	return (idx);
}

// index of the biggest rank in b that is still smaller than "rank"
// returns -1 if every element in b is bigger
int	ps_target_idx_b(t_stack *b, int rank)
{
	int	i;
	int	idx;
	int	best;

	i = 0;
	idx = -1;
	best = -1;
	while (b)
	{
		if (b->rank < rank && b->rank > best)
		{
			best = b->rank;
			idx = i;
		}
		i++;
		b = b->next;
	}
	return (idx);
}
