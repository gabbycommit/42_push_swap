/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_pull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:39:48 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 09:30:18 by hukhaw           ###   ########.fr       */
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

// number of rotations needed to reach position idx (either direction)
static int	ps_dist(int idx, int size)
{
	if (idx <= size / 2)
		return (idx);
	return (size - idx);
}

static void	ps_pull_one(t_stack **a, t_stack **b, t_config *config, int rank)
{
	int	size;

	size = (int)ps_lstcount(*b);
	ps_rot_b_dir(ps_find_target_idx(*b, rank), size, b, config);
	ps_push_a(a, b, config);
}

// pull the biggest rank back to a. If the 2nd biggest is closer to the top,
// pull it first, then the biggest, and fix the order with sa
void	ps_pull_back(t_stack **a, t_stack **b, t_config *config)
{
	int	size;
	int	max;
	int	dist_largest;
	int	dist_second_largest;

	size = (int)ps_lstcount(*b);
	while (*b)
	{
		max = size - 1;
		dist_largest = ps_dist(ps_find_target_idx(*b, max), size);
		dist_second_largest = ps_dist(ps_find_target_idx(*b, max - 1), size);
		if (size >= 2 && dist_second_largest < dist_largest)
		{
			ps_pull_one(a, b, config, max - 1);
			ps_pull_one(a, b, config, max);
			ps_swap_a(a, config);
			size -= 2;
		}
		else
		{
			ps_pull_one(a, b, config, max);
			size--;
		}
	}
}
