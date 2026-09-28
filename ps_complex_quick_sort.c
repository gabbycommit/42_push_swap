/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_quick_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 22:38:46 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 15:14:27 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_quick_sort_a(
				t_stack **a, t_stack **b, t_config *config, int size);

static int	*ps_partition_b(
				t_stack **a, t_stack **b, t_config *config, int size)
{
	int	i;
	int	pivot;
	int	*push_rotate_count;

	i = 0;
	pivot = ps_get_pivot(*b, size);
	push_rotate_count = (int *)malloc(sizeof(int) * 2);
	if (!push_rotate_count)
		return (NULL);
	push_rotate_count[0] = 0;
	push_rotate_count[1] = 0;
	while (i < size)
	{
		if ((*b)->rank >= pivot && ++push_rotate_count[0])
			ps_push_a(a, b, config);
		else if (++push_rotate_count[1])
			ps_rotate_b(b, config);
		i++;
	}
	return (push_rotate_count);
}

static void	ps_quick_sort_b(
				t_stack **a, t_stack **b, t_config *config, int size)
{
	int	*push_rotate_count;

	if (size == 0)
		return ;
	if (size == 1)
	{
		ps_push_a(a, b, config);
		return ;
	}
	if (size == 2)
	{
		ps_complex_sort_two(b, config, 0);
		ps_push_a(a, b, config);
		ps_push_a(a, b, config);
		return ;
	}
	push_rotate_count = ps_partition_b(a, b, config, size);
	if (!push_rotate_count)
		return ;
	ps_quick_sort_a(a, b, config, push_rotate_count[0]);
	ps_restore(b, config, push_rotate_count[1], 0);
	ps_quick_sort_b(a, b, config, size - push_rotate_count[0]);
	free(push_rotate_count);
}

static int	*ps_partition_a(
				t_stack **a, t_stack **b, t_config *config, int size)
{
	int	i;
	int	pivot;
	int	*push_rotate_count;

	i = 0;
	pivot = ps_get_pivot(*a, size);
	push_rotate_count = (int *)malloc(sizeof(int) * 2);
	if (!push_rotate_count)
		return (NULL);
	push_rotate_count[0] = 0;
	push_rotate_count[1] = 0;
	while (i < size)
	{
		if ((*a)->rank >= pivot && ++push_rotate_count[1])
			ps_rotate_a(a, config);
		else if (++push_rotate_count[0])
			ps_push_b(a, b, config);
		i++;
	}
	return (push_rotate_count);
}

static void	ps_quick_sort_a(
				t_stack **a, t_stack **b, t_config *config, int size)
{
	int	*push_rotate_count;

	if (size <= 1 || ps_is_sorted(*a))
		return ;
	if (size == 2)
	{
		ps_complex_sort_two(a, config, 1);
		return ;
	}
	push_rotate_count = ps_partition_a(a, b, config, size);
	if (!push_rotate_count)
		return ;
	ps_restore(a, config, push_rotate_count[1], 1);
	ps_quick_sort_a(a, b, config, size - push_rotate_count[0]);
	ps_quick_sort_b(a, b, config, push_rotate_count[0]);
	free(push_rotate_count);
}

void	ps_complex_quick_sort(t_stack **a, t_stack **b, t_config *config)
{
	ps_init_rank(*a);
	ps_quick_sort_a(a, b, config, ps_lstcount(*a));
}
