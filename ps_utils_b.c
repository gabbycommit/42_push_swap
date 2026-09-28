/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:38:12 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 18:01:36 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_process_space_and_sign(const char *s, int *i, int *sign)
{
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == ' ')
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

long	ps_atol(const char *s)
{
	long	result;
	int		sign;
	int		i;
	int		digit;

	result = 0;
	sign = 1;
	i = 0;
	ps_process_space_and_sign(s, &i, &sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		if (result > (LONG_MAX - digit) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = (result * 10) + digit;
		i++;
	}
	return (result * sign);
}

double	ps_compute_disorder(t_stack *a)
{
	double	mistakes;
	double	total_pairs;
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

int	ps_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
