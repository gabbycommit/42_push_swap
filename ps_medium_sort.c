/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:40:05 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/27 21:49:17 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_medium_sort(t_stack **a, t_stack **b, t_config *config)
{
	int	n;

	ps_init_rank(*a);
	n = (int)ps_lstcount(*a);
	if (n == 1 || ps_is_sorted(*a))
		return ;
	if (n <= 3)
	{
		ps_sort_small(a, config);
		return ;
	}
	ps_push_chunks(a, b, config, n);
	ps_pull_back(a, b, config);
}
