/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:20:40 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:41:25 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static void	ps_free_all_stack(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	while (b)
	{
		temp = b->next;
		free(b);
		b = temp;
	}
}

static int	ps_is_sorted(t_stack *a)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = ps_parse_and_validation(argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = NULL;
	if (!ps_exec_ops(0, &a, &b))
		return (ps_free_all_stack(a, b), write(2, "Error\n", 6), 1);
	if (ps_is_sorted(a) && !b)
		return (ps_free_all_stack(a, b), ft_putstr_fd("OK\n", 1), 0);
	else
		return (ps_free_all_stack(a, b), ft_putstr_fd("KO\n", 1), 0);
}
