/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:25:06 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 10:34:24 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* where min / mid / max go, depending on where the chunk is now */
static void	ps_set_dest_loc(t_loc loc, t_complex_chunk *dest)
{
	dest[0].loc = BOTTOM_B;
	dest[1].loc = TOP_B;
	dest[2].loc = TOP_A;
	if (loc == TOP_A)
		dest[2].loc = BOTTOM_A;
	else if (loc == TOP_B || loc == BOTTOM_B)
		dest[1].loc = BOTTOM_A;
	if (loc == BOTTOM_B)
		dest[0].loc = TOP_B;
}

/* split sizes: max part = p_max elements, mid = p_mid, min = the rest */
static void	ps_set_dest_size(t_complex_chunk *chunk, t_complex_chunk *dest)
{
	int	p_max;
	int	p_mid;

	p_max = chunk->size / 3;
	if (ps_in_a(chunk->loc))
		p_mid = chunk->size / 3;
	else
		p_mid = chunk->size / 2 - chunk->size / 3;
	if (ps_in_a(chunk->loc) && chunk->size < 15)
		p_mid = chunk->size - p_max;
	dest[2].size = p_max;
	dest[1].size = p_mid;
	dest[0].size = chunk->size - p_max - p_mid;
	dest[0].lo = chunk->lo;
	dest[1].lo = chunk->lo + dest[0].size;
	dest[2].lo = dest[1].lo + p_mid;
}

void	ps_split_chunk(t_ps *ps, t_complex_chunk *chunk, t_complex_chunk *dest)
{
	int	i;
	int	rank;

	ps_set_dest_loc(chunk->loc, dest);
	ps_set_dest_size(chunk, dest);
	i = 0;
	while (i < chunk->size)
	{
		rank = ps_peek(ps, chunk->loc);
		if (rank >= dest[2].lo)
			ps_move(ps, chunk->loc, dest[2].loc);
		else if (rank >= dest[1].lo)
			ps_move(ps, chunk->loc, dest[1].loc);
		else
			ps_move(ps, chunk->loc, dest[0].loc);
		i++;
	}
}
