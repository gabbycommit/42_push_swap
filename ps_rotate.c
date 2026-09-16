/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:30:23 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/16 16:35:59 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_rotate_a(t_stack **a, t_config *config, int is_write)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ps_lstlast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next= first;
	first->prev = last;
	first->next = NULL;
	if (is_write)
	{
		config->ra++;
		write(1, "ra\n", 3);
	}
}

void	ps_rotate_b(t_stack **b, t_config *config, int is_write)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	last = ps_lstlast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	last->next= first;
	first->prev = last;
	first->next = NULL;
	if (is_write)
	{
		config->rb++;
		write(1, "rb\n", 3);
	}
}

void	ps_rr(t_stack **a, t_stack **b, t_config *config)
{
	ps_rotate_a(a, config, 0);
	ps_rotate_b(b, config, 0);
	config->rr++;
	write(1, "rr\n", 3);
}
