/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:12:04 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 11:27:19 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// for sa & sb use
void	ps_swap_a(t_stack **a, t_counter *count, int is_ss)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
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
	*a = second;
	if (!is_ss)
	{
		count->sa++;
		write(1, "sa", 2);
	}
}

void	ps_swap_b(t_stack **b, t_counter *count, int is_ss)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
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
	*b = second;
	if (is_ss)
	{
		count->sb++;
		write(1, "sb", 2);
	}
}

void	ps_ss(t_stack **a, t_stack **b, t_counter *count)
{
	ps_swap_a(a, 0);
	ps_swap_b(b, 0);
	count->ss++;
	write(1, "ss", 2);
}
