/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_sort_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:21:14 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 10:36:41 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* A holds exactly these 3 numbers: rotations are safe */
static void	ps_sort_three_alone(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = (*ps->a)->rank;
	second = (*ps->a)->next->rank;
	third = (*ps->a)->next->next->rank;
	if (first > second && first > third)
		ps_rotate_a(ps->a, ps->config);
	else if (second > first && second > third)
		ps_reverse_rotate_a(ps->a, ps->config);
	if ((*ps->a)->rank > (*ps->a)->next->rank)
		ps_swap_a(ps->a, ps->config);
}

/* top 3 of A must be sorted without touching what is under them */
static void	ps_sort_three_top_a(t_ps *ps)
{
	t_stack	*a;

	a = *ps->a;
	while (!(a->rank < a->next->rank && a->next->rank < a->next->next->rank))
	{
		if (a->rank > a->next->rank)
			ps_swap_a(ps->a, ps->config);
		else
		{
			ps_rotate_a(ps->a, ps->config);
			ps_swap_a(ps->a, ps->config);
			ps_reverse_rotate_a(ps->a, ps->config);
		}
		a = *ps->a;
	}
}

void	ps_sort_small_chunk(t_ps *ps, t_complex_chunk *chunk)
{
	int	i;

	i = 0;
	while (chunk->loc != TOP_A && i++ < chunk->size)
		ps_move(ps, chunk->loc, TOP_A);
	if (chunk->size == 2 && (*ps->a)->rank > (*ps->a)->next->rank)
		ps_swap_a(ps->a, ps->config);
	else if (chunk->size == 3 && ps_lstcount(*ps->a) == 3)
		ps_sort_three_alone(ps);
	else if (chunk->size == 3)
		ps_sort_three_top_a(ps);
}
