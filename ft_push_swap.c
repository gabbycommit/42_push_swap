/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:17:54 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/12 22:56:55 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_config	*ps_new_config(void)
{
	t_config	*new_config;

	new_config = (t_config *)malloc(sizeof(t_config));
	if (!new_config)
		return (NULL);
	new_config->sa = 0;
	new_config->sb = 0;
	new_config->ss = 0;
	new_config->pa = 0;
	new_config->pb = 0;
	new_config->ra = 0;
	new_config->rb = 0;
	new_config->rr = 0;
	new_config->rra = 0;
	new_config->rrb = 0;
	new_config->rrr = 0;
	new_config->disorder = 0;
	new_config->bench = 0;
	new_config->strategy = "Adaptive";
	new_config->symbol = "";
	return (new_config);
}

static void	ps_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

static void	print_a(t_stack *a)
{
	printf("\n-----\n\n");
	while (a)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	*config;

	if (argc == 1)
		return (0);
	config = ps_new_config();
	if (!config)
		return (write(2, "Error\n", 6), 1);
	a = ps_parse_and_validation(argc, argv, config);
	if (!a)
		return (free(config), write(2, "Error\n", 6), 1);
	b = NULL;
	ps_compute_disorder_and_symbol(a, config);
	ps_radix_lsd_sort(&a, &b, config, ps_lstcount(a));
	print_a(a);
	ps_free_stack(a);
	ps_free_stack(b);
	if (config->bench)
		ps_print_bench(config);
	free(config);
	return (0);
}
