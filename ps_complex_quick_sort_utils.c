/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_quick_sort_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 09:07:47 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 09:31:30 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ps_get_pivot(t_stack *stack, int size)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = stack->rank;
	min = stack->rank;
	while (i < size)
	{
		if (stack->rank < min)
			min = stack->rank;
		else if (stack->rank > max)
			max = stack->rank;
		i++;
		stack = stack->next;
	}
	return ((max + min) / 2);
}

void	ps_complex_sort_two(t_stack **stack, t_config *config, int is_a)
{
	if (is_a && (*stack)->rank > (*stack)->next->rank)
		ps_swap_a(stack, config);
	else if (!is_a && (*stack)->rank < (*stack)->next->rank)
		ps_swap_b(stack, config);
}

void	ps_restore(
			t_stack **stack, t_config *config, int rotate_count, int is_a)
{
	int	i;

	i = 0;
	if (rotate_count == ps_lstcount(*stack))
		return ;
	while (i < rotate_count)
	{
		if (is_a)
			ps_reverse_rotate_a(stack, config);
		else
			ps_reverse_rotate_b(stack, config);
		i++;
	}
}
