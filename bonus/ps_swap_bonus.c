/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:12:04 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 15:17:09 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	ps_swap_a(t_stack **a, t_config *config)
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
}

void	ps_swap_b(t_stack **b, t_config *config, int is_write)
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
}

void	ps_ss(t_stack **a, t_stack **b, t_config *config)
{
	ps_swap_a(a, config, 0);
	ps_swap_b(b, config, 0);
}
