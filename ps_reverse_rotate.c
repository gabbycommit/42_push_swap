/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:31:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/16 16:47:00 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_reverse_rotate_a(t_stack **a, t_config *config, int is_write)
{
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last = ps_lstlast(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (is_write)
	{
		config->rra++;
		write(1, "rra\n", 4);
	}
}

void	ps_reverse_rotate_b(t_stack **b, t_config *config, int is_write)
{
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	last = ps_lstlast(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	if (is_write)
	{
		config->rrb++;
		write(1, "rrb\n", 4);
	}
}

void	ps_rrr(t_stack **a, t_stack **b, t_config *config)
{
	ps_reverse_rotate_a(a, config, 0);
	ps_reverse_rotate_b(b, config, 0);
	config->rrr++;
	write(1, "rrr\n", 4);
}
