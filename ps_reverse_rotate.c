/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:31:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/09 16:12:10 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_reverse_rotate_a(t_stack **a, t_config *config, int is_write)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev_last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (ps_lstcount(*a) == 2)
		ps_swap_a(a, config, 0);
	else
	{
		first = *a;
		last = ps_lstlast(*a);
		prev_last = last->prev;
	}
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	prev_last->next = NULL;
	*a = last;
	if (is_write)
	{
		config->rra++;
		write(1, "rra\n", 4);
	}
}

void	ps_reverse_rotate_b(t_stack **b, t_config *config, int is_write)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prev_last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	if (ps_lstcount(*b) == 2)
		ps_swap_b(b, config, 0);
	else
	{
		first = *b;
		last = ps_lstlast(*b);
		prev_last = last->prev;
	}
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	prev_last->next = NULL;
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
