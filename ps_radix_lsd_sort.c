/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_lsd_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:20:42 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/13 11:10:55 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_get_max_bits(int size)
{
	int	max;
	int	bits;

	max = 1;
	bits = 0;
	while (max < size)
	{
		max *= 2;
		bits++;
	}
	return (bits);
}

static void	ps_restore_to_a(
	t_stack **a, t_stack **b, t_config *config, size_t b_size)
{
	size_t	i;

	i = 0;
	while (i < b_size)
	{
		ps_push_a(a, b, config);
		i++;
	}
}

void	ps_radix_lsd_sort(
		t_stack **a, t_stack **b, t_config *config, size_t size)
{
	int		max_bit;
	int		bit;
	size_t	i;

	max_bit = ps_get_max_bits(size);
	bit = 0;
	ps_init_rank(*a);
	while (bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->rank >> bit) & 1)
				ps_rotate_a(a, config, 1);
			else
				ps_push_b(a, b, config);
			i++;
		}
		ps_restore_to_a(a, b, config, ps_lstcount(*b));
		bit++;
	}
}
