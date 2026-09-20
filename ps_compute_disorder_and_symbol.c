/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compute_disorder_and_symbol.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 15:12:08 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/20 12:02:48 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ps_compute_disorder_and_symbol(t_stack *a, t_config *config)
{
	config->disorder = ps_compute_disorder(a);
	if (ft_strncmp(config->strategy, "Simple", 7) == 0)
		config->symbol = "O(n2)";
	else if (ft_strncmp(config->strategy, "Medium", 7) == 0)
		config->symbol = "O(n√n)";
	else if (ft_strncmp(config->strategy, "Complex", 8) == 0)
		config->symbol = "O(n log n)";
	else if (ft_strncmp(config->strategy, "Adaptive", 9) == 0)
	{
		if (config->disorder < 0.2)
			config->symbol = "O(n2)";
		else if (config->disorder >= 0.2 && config->disorder < 0.5)
			config->symbol = "O(n√n)";
		else
			config->symbol = "O(n log n)";
	}
}
