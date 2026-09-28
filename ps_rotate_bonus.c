/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:30:23 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 15:09:33 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	ps_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ps_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ps_rotate_a(t_stack **a)
{
	ps_rotate(a);
}

void	ps_rotate_b(t_stack **b)
{
	ps_rotate(b);
}

void	ps_rr(t_stack **a, t_stack **b)
{
	ps_rotate(a);
	ps_rotate(b);
}
