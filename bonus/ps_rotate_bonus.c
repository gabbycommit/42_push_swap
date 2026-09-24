/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:30:23 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 15:16:45 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	ps_rotate_a(t_stack **a, t_config *config)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ps_lstlast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ps_rotate_b(t_stack **b, t_config *config)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	last = ps_lstlast(*b);
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ps_rr(t_stack **a, t_stack **b, t_config *config)
{
	ps_rotate_a(a, config);
	ps_rotate_b(b, config);
}
