/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:53:21 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:53:54 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

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
