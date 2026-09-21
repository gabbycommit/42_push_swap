/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:48:46 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/21 11:28:48 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// to calculate the sqrt of total num
// will be used in chunk size calculation
int	ps_isqrt(int n)
{
	int	r;

	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	r = 2;
	while ((r * r) <= n)
		r++;
	return (r - 1);
}

// to calculate how many num inside a chunk
// chunk size = 1.6 * sqrt(n)
int	ps_chunk_size(int n)
{
	int	size;

	size = ps_isqrt(n) * 8 / 5;
	if (size < 1)
		size = 1;
	return (size);
}

// bring node at position idx of stack a to the top (shortest direction)
void	ps_rot_a_dir(int idx, int size, t_stack **a, t_config *config)
{
	if (idx <= size / 2)
	{
		while (idx-- > 0)
			ps_rotate_a(a, config, 1);
	}
	else
	{
		while (idx++ < size)
			ps_reverse_rotate_a(a, config, 1);
	}
}

// bring node at position idx of stack b to the top (shortest direction)
void	ps_rot_b_dir(int idx, int size, t_stack **b, t_config *config)
{
	if (idx <= size / 2)
	{
		while (idx-- > 0)
			ps_rotate_b(b, config, 1);
	}
	else
	{
		while (idx++ < size)
			ps_reverse_rotate_b(b, config, 1);
	}
}
