/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:12:04 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 09:34:27 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	first->prev = second;
	if (third)
	{
		first->next = third;
		third->prev = first;
	}
	else
		first->next = NULL;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void	ps_swap_a(t_stack **a, t_config *config)
{
	ps_swap(a);
	config->sa++;
	write(1, "sa\n", 3);
}

void	ps_swap_b(t_stack **b, t_config *config)
{
	ps_swap(b);
	config->sb++;
	write(1, "sb\n", 3);
}

void	ps_ss(t_stack **a, t_stack **b, t_config *config)
{
	ps_swap(a);
	ps_swap(b);
	config->ss++;
	write(1, "ss\n", 3);
}
