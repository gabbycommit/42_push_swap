/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_msd_base3_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:46:13 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/16 15:29:46 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_get_digit_b3(int rank, int pass)
{
	while (pass-- > 0)
		rank /= 3;
	return (rank % 3);
}

static void	ps_restore(t_stack **stack, t_config *config, int count, int is_a)
{
	if (count == ps_lstcount(*stack))
		return ;
	while (count-- > 0)
	{
		if (is_a)
			ps_reverse_rotate_a(stack, config, 1);
		else
			ps_reverse_rotate_b(stack, config, 1);
	}
}

static void	ps_sort_small_a(t_stack **a, t_stack **b, t_config *config, int size)
{
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			ps_swap_a(a, config, 1);
		return ;
	}
	if ((*a)->rank > (*a)->next->rank)
		ps_swap_a(a, config, 1);
	if ((*a)->next->rank > (*a)->next->next->rank)
	{
		ps_push_b(a, b, config);
		if ((*a)->rank > (*a)->next->rank)
			ps_swap_a(a, config, 1);
		ps_push_a(a, b, config);
		if ((*a)->rank > (*a)->next->rank)
			ps_swap_a(a, config, 1);
	}
}

static void	ps_msd_b_base3(t_stack **a, t_stack **b, t_config *config, t_range *r);

static void	ps_msd_a_base3(t_stack **a, t_stack **b, t_config *config, t_range *r)
{
	int		i;
	int		c[3];
	int		digit;
	t_range	temp;

	if (r->size <= 3 || r->pass < 0)
	{
		ps_sort_small_a(a, b, config, r->size);
		return ;
	}
	i = 0;
	c[0] = 0; c[1] = 0; c[2] = 0;
	while (i++ < r->size)
	{
		digit = ps_get_digit_b3((*a)->rank, r->pass);
		if (digit == 2 && ++c[2])
			ps_rotate_a(a, config, 1);
		else if (digit == 1 && ++c[1])
			ps_push_b(a, b, config);
		else if (digit == 0 && ++c[0])
		{
			ps_push_b(a, b, config);
			ps_rotate_b(b, config, 1);
		}
	}
	ps_restore(a, config, c[2], 1);
	temp.pass = r->pass - 1;
	temp.size = c[2];
	ps_msd_a_base3(a, b, config, &temp);
	temp.size = c[1];
	ps_msd_b_base3(a, b, config, &temp);
	ps_restore(b, config, c[0], 0);
	temp.size = c[0];
	ps_msd_b_base3(a, b, config, &temp);
}

static void	ps_msd_b_base3(t_stack **a, t_stack **b, t_config *config, t_range *r)
{
	int		i;
	int		c[3];
	int		digit;
	t_range	temp;

	if (r->size == 0)
		return ;
	if (r->size <= 3 || r->pass < 0)
	{
		i = r->size;
		while (i-- > 0)
			ps_push_a(a, b, config);
		ps_sort_small_a(a, b, config, r->size);
		return ;
	}
	i = 0;
	c[0] = 0; c[1] = 0; c[2] = 0;
	while (i++ < r->size)
	{
		digit = ps_get_digit_b3((*b)->rank, r->pass);
		if (digit == 2 && ++c[2])
			ps_push_a(a, b, config);
		else if (digit == 1 && ++c[1])
		{
			ps_push_a(a, b, config);
			ps_rotate_a(a, config, 1);
		}
		else if (digit == 0 && ++c[0])
			ps_rotate_b(b, config, 1);
	}
	temp.pass = r->pass - 1;
	temp.size = c[2];
	ps_msd_a_base3(a, b, config, &temp);
	ps_restore(a, config, c[1], 1);
	temp.size = c[1];
	ps_msd_a_base3(a, b, config, &temp);
	ps_restore(b, config, c[0], 0);
	temp.size = c[0];
	ps_msd_b_base3(a, b, config, &temp);
}

void	ps_radix_msd_base3_sort(t_stack **a, t_stack **b, t_config *config)
{
	t_range	r;
	int		p;

	ps_init_rank(*a);
	r.size = ps_lstcount(*a);
	if (r.size <= 1)
		return ;
	r.pass = 0;
	p = 1;
	while (p < r.size)
	{
		p *= 3;
		r.pass++;
	}
	r.pass--;
	ps_msd_a_base3(a, b, config, &r);
}
