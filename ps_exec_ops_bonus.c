/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exec_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 09:10:32 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:13:26 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static int	ps_validate_and_exec_ops(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (ps_swap_a(a), 1);
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (ps_swap_b(b), 1);
	if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ps_ss(a, b), 1);
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (ps_push_a(a, b), 1);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		return (ps_push_b(a, b), 1);
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (ps_rotate_a(a), 1);
	if (ft_strncmp(line, "rb\n", 4) == 0)
		return (ps_rotate_b(b), 1);
	if (ft_strncmp(line, "rr\n", 4) == 0)
		return (ps_rr(a, b), 1);
	if (ft_strncmp(line, "rra\n", 5) == 0)
		return (ps_reverse_rotate_a(a), 1);
	if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (ps_reverse_rotate_b(b), 1);
	if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (ps_rrr(a, b), 1);
	else
		return (0);
}

int	ps_exec_ops(int fd, t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (!ps_validate_and_exec_ops(line, a, b))
		{
			free(line);
			return (0);
		}
		else
			free(line);
	}
}
