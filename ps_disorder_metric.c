/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_disorder_metric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:35:09 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/03 11:44:06 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*next_node;

	mistakes = 0;
	total_pairs = 0;
	next_node = a->next;
	while (a)
	{
		while (next)
		{
			total_pairs++;
			if (a->num > next->num)
				mistakes++;
			next_node = next_node->next;
		}
		a = a->next;
	}
	return (mistakes / total_pairs);
}
