/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:38:12 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/09 20:41:50 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ps_atol(const char *s)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

float	ps_compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*next_node;

	mistakes = 0;
	total_pairs = 0;
	while (a)
	{
		next_node = a->next;
		while (next_node)
		{
			total_pairs++;
			if (a->num > next_node->num)
				mistakes++;
			next_node = next_node->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
