/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_quick_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:23:36 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 10:33:11 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_fix_loc(t_ps *ps, t_complex_chunk *chunk)
{
	if (chunk->loc == BOTTOM_A && chunk->size == ps_lstcount(*ps->a))
		chunk->loc = TOP_A;
	else if (chunk->loc == BOTTOM_B && chunk->size == ps_lstcount(*ps->b))
		chunk->loc = TOP_B;
}

/* If the chunk's biggest number is directly reachable, send it straight
** onto the sorted part of A instead of splitting it again. */
static void	ps_easy_sort(t_ps *ps, t_complex_chunk *chunk)
{
	while (chunk->loc != TOP_A && chunk->size > 0
		&& ps_peek(ps, chunk->loc) == chunk->lo + chunk->size - 1)
	{
		ps_move(ps, chunk->loc, TOP_A);
		chunk->size--;
	}
}

static void	ps_chunk_sort(t_ps *ps, t_complex_chunk *chunk)
{
	t_complex_chunk	dest[3];

	ps_fix_loc(ps, chunk);
	ps_easy_sort(ps, chunk);
	if (chunk->size <= 3)
	{
		ps_sort_small_chunk(ps, chunk);
		return ;
	}
	ps_split_chunk(ps, chunk, dest);
	ps_chunk_sort(ps, &dest[2]);
	ps_chunk_sort(ps, &dest[1]);
	ps_chunk_sort(ps, &dest[0]);
}

static int	ps_min_rank(t_stack *stack)
{
	int	min;

	min = stack->rank;
	while (stack)
	{
		if (stack->rank < min)
			min = stack->rank;
		stack = stack->next;
	}
	return (min);
}

void	ps_complex_quick_sort(t_stack **a, t_stack **b, t_config *config)
{
	t_ps			ps;
	t_complex_chunk	all;

	if (!a || !*a)
		return ;
	ps_init_rank(*a);
	if (ps_is_sorted(*a))
		return ;
	ps.a = a;
	ps.b = b;
	ps.config = config;
	all.loc = TOP_A;
	all.size = ps_lstcount(*a);
	all.lo = ps_min_rank(*a);
	ps_chunk_sort(&ps, &all);
}
