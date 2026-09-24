/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:31:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 15:16:55 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	ps_reverse_rotate_a(t_stack **a, t_config *config)
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
}

void	ps_reverse_rotate_b(t_stack **b, t_config *config)
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
}

void	ps_rrr(t_stack **a, t_stack **b, t_config *config)
{
	ps_reverse_rotate_a(a, config);
	ps_reverse_rotate_b(b, config);
}
