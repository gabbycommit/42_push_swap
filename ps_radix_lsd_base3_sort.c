/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_lsd_base3_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 22:20:42 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/13 14:00:13 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_get_total_passes(int size)
{
	int	max;
	int	passes;

	max = 1;
	passes = 0;
	while (max < size)
	{
		max *= 3;
		passes++;
	}
	return (passes);
}

static int	ps_get_digit(int rank, int pass)
{
	int	divisor;
	int	i;

	divisor = 1;
	i = 0;
	while (i < pass)
	{
		divisor *= 3;
		i++;
	}
	return ((rank / divisor) % 3);
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

static void	ps_restore_only_1(
		t_stack **a, t_stack **b, t_config *config, int pass)
{
	size_t	b_size;
	size_t	i;
	int		digit;

	b_size = ps_lstcount(*b);
	i = 0;
	while (i < b_size)
	{
		digit = ps_get_digit((*b)->rank, pass);
		if (digit == 1)
			ps_push_a(a, b, config);
		else
			ps_rotate_b(b, config, 1);
		i++;
	}
}

void	ps_radix_lsd_sort(
		t_stack **a, t_stack **b, t_config *config, size_t size)
{
	int		total_passes;
	int		pass;
	size_t	i;
	int		digit;

	total_passes = ps_get_total_passes(size);
	pass = 0;
	ps_init_rank(*a);
	while (pass < total_passes)
	{
		i = 0;
		while (i < size)
		{
			digit = ps_get_digit((*a)->rank, pass);
			if (digit == 0)
				ps_rotate_a(a, config, 1);
			else
				ps_push_b(a, b, config);
			i++;
		}
		ps_restore_only_1(a, b, config, pass);
		ps_restore_to_a(a, b, config, ps_lstcount(*b));
		pass++;
	}
}
