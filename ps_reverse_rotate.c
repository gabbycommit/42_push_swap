/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:31:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 09:35:20 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ps_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	ps_reverse_rotate_a(t_stack **a, t_config *config)
{
	ps_reverse_rotate(a);
	config->rra++;
	write(1, "rra\n", 4);
}

void	ps_reverse_rotate_b(t_stack **b, t_config *config)
{
	ps_reverse_rotate(b);
	config->rrb++;
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack **a, t_stack **b, t_config *config)
{
	ps_reverse_rotate(a);
	ps_reverse_rotate(b);
	config->rrr++;
	write(1, "rrr\n", 4);
}
