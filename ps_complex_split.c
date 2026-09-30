/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:25:06 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/30 13:05:27 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* where min / mid / max go, depending on where the chunk is now 
 * imagine that we always have 4 location, and 1 is used for sorted area
 * 2 = MAX, 1 = MEDIUM, 0 = MIN
 * current chunk loc					the available area
 * 	TOP A							BOTTOM A, TOP B, BOTTOM B
 * 	BOTTOM A						TOP A, TOP B, BOTTOM B
 * 	TOP B							TOP A, BOTTOM A, BOTTOM B
 * 	BOTTOM B						TOP A, BOTTOM A, TOP B
 * */
static void	ps_set_dest_loc(t_loc loc, t_complex_chunk *dest)
{
	dest[0].loc = BOTTOM_B;
	dest[1].loc = TOP_B;
	dest[2].loc = TOP_A;
	if (loc == TOP_A)
		dest[2].loc = BOTTOM_A;
	else if (loc == TOP_B || loc == BOTTOM_B)
	{
		dest[1].loc = BOTTOM_A;
		if (loc == BOTTOM_B)
			dest[0].loc = TOP_B;
	}
}

static void	ps_set_dest_size(t_complex_chunk *chunk, t_complex_chunk *dest)
{
	int	max_size;
	int	mid_size;

	max_size = chunk->size / 3;
	mid_size = chunk->size / 3;
	if (ps_in_a(chunk->loc) && chunk->size < 15)
		mid_size = chunk->size - max_size;
	dest[2].size = max_size;
	dest[1].size = mid_size;
	dest[0].size = chunk->size - max_size - mid_size;
	dest[0].lo = chunk->lo;
	dest[1].lo = chunk->lo + dest[0].size;
	dest[2].lo = dest[1].lo + mid_size;
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
