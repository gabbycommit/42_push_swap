/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 11:35:59 by hukhaw            #+#    #+#        */
/*   Updated: 2026/09/26 09:35:47 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_sort_two(t_stack **a, t_config *config)
{
	if ((*a)->rank > (*a)->next->rank)
		ps_swap_a(a, config);
}

// first condition: 312, 321
// second condition: 132, 231
// else condition: 123, 213
static void	ps_sort_three(t_stack **a, t_config *config)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->rank;
	second = (*a)->next->rank;
	third = (*a)->next->next->rank;
	if (first > second && first > third)
	{
		ps_rotate_a(a, config);
		ps_sort_two(a, config);
	}
	else if (second > first && second > third)
	{
		ps_reverse_rotate_a(a, config);
		ps_sort_two(a, config);
	}
	else
		ps_sort_two(a, config);
}

void	ps_sort_small(t_stack **a, t_config *config)
{
	int	size;

	size = ps_lstcount(*a);
	if (size == 2)
		ps_sort_two(a, config);
	if (size == 3)
		ps_sort_three(a, config);
}
