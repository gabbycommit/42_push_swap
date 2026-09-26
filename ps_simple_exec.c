/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 11:33:14 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 09:26:12 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// n > 0 : ra n times, n < 0 : rra -n times
void	ps_rot_a(int n, t_stack **a, t_config *config)
{
	while (n > 0)
	{
		ps_rotate_a(a, config);
		n--;
	}
	while (n < 0)
	{
		ps_reverse_rotate_a(a, config);
		n++;
	}
}

// n > 0 : rb n times, n < 0 : rrb -n times
void	ps_rot_b(int n, t_stack **b, t_config *config)
{
	while (n > 0)
	{
		ps_rotate_b(b, config);
		n--;
	}
	while (n < 0)
	{
		ps_reverse_rotate_b(b, config);
		n++;
	}
}

// first share moves with rr / rrr, then do the leftovers one stack at a time
void	ps_exec_move(t_move *m, t_stack **a, t_stack **b, t_config *config)
{
	while (m->a > 0 && m->b > 0)
	{
		ps_rr(a, b, config);
		m->a--;
		m->b--;
	}
	while (m->a < 0 && m->b < 0)
	{
		ps_rrr(a, b, config);
		m->a++;
		m->b++;
	}
	ps_rot_a(m->a, a, config);
	ps_rot_b(m->b, b, config);
}
