/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:20:40 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 17:51:16 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

int	main(int agrc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return ;
	a = ps_parse_and_validation(argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = NULL;
}
