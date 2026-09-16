/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_msd_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:46:13 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/16 12:20:04 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
static void	ps_msd_a(t_stack **a, t_stack **b, t_config *config, t_range *r);
static void	ps_msd_b(t_stack **a, t_stack **b, t_config *config, t_range *r);

static int	ps_get_max_bits(int size)
{
	int	bits;
	int	max;

	max = 1;
	bits = 0;
	while (max < size)
	{
		max *= 2;
		bits++;
	}
	return (bits);
}

static void	ps_restore(t_stack **stack, t_config *config, int count, int is_a)
{
	if (count == ps_lstcount(*stack))
		return ;
	while (count > 0)
	{
		if (is_a)
			ps_reverse_rotate_a(stack, config, 1);
		else
			ps_reverse_rotate_b(stack, config, 1);
		count--;
	}
}

static void ps_msd_b(t_stack **a, t_stack **b, t_config *config, t_range *r)
{
	int		i;
	int		count_a;
	int		count_b;
	t_range	temp;

	if (r->size == 0)
		return ;
	if (r->bit < 0)
	{
		while (r->size-- > 0)
			ps_push_a(a, b, config);
		return ;
	}
	if (r->size == 1)
	{
		ps_push_a(a, b, config);
		return ;
	}
	i = 0;
	count_a = 0;
	count_b = 0;
	while (i++ < r->size)
	{
		if ((((*b)->rank >> r->bit) & 1) == 1 && ++count_a)
			ps_push_a(a, b, config);
		else if (++count_b)
			ps_rotate_b(b, config, 1);
	}
	ps_restore(b, config, count_b, 0);
	temp.size = count_a;
	temp.bit = r->bit - 1; 
	ps_msd_a(a, b, config, &temp);
	temp.size = count_b;
	temp.bit = r->bit - 1;
	ps_msd_b(a, b, config, &temp);
}

static void	ps_msd_a(t_stack **a, t_stack **b, t_config *config, t_range *r)
{
	int		i;
	int		count_a;
	int		count_b;
	t_range	temp;

	if (r->size <= 1 || r->bit < 0)
		return ;
	i = 0;
	count_a = 0;
	count_b = 0;
	while (i++ < r->size)
	{
		if ((((*a)->rank >> r->bit) & 1) == 0 && ++count_b)
			ps_push_b(a, b, config);
		else if (++count_a)
			ps_rotate_a(a, config, 1);
	}
	ps_restore(a, config, count_a, 1);
	temp.size = count_a;
	temp.bit = r->bit - 1; 
	ps_msd_a(a, b, config, &temp);
	temp.size = count_b;
	temp.bit = r->bit - 1;
	ps_msd_b(a, b, config, &temp);
}

void	ps_radix_msd_sort(t_stack **a, t_stack **b, t_config *config)
{
	t_range	r;

	ps_init_rank(*a);
	r.size = ps_lstcount(*a);
	r.bit = ps_get_max_bits(r.size) - 1;
	if (r.size <= 1)
		return ;
	ps_msd_a(a, b, config, &r);
}
