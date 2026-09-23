/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 11:37:12 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 12:16:58 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// disoder = 0 ~ 1
// interger part *= 100, e.g 0.5675245... * 100 = 56.725..
// e.g decimal part:
// 56.7252.. - 56 = 0.7252.., 
// 0.7252..*100 = 72.52.., 
// 72.52 + 0.5 = 73.02... rounding to two decimal places
static void	ps_print_disorder(double disorder)
{
	int	interger_part;
	int	decimal_part;

	interger_part = (int)(disorder * 100);
	decimal_part = (int)((disorder * 100 - interger_part) * 100 + 0.5);
	if (decimal_part >= 100)
	{
		interger_part += 1;
		decimal_part = 0;
	}
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(interger_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part, 2);
	write(2, "%\n", 2);
}

static int	ps_cal_total_ops(t_config *config)
{
	int	total;

	total = 0;
	total += config->sa;
	total += config->sb;
	total += config->ss;
	total += config->pa;
	total += config->pb;
	total += config->ra;
	total += config->rb;
	total += config->rr;
	total += config->rra;
	total += config->rrb;
	total += config->rrr;
	return (total);
}

static void	ps_putstr_num(char *str, int num)
{
	ft_putstr_fd(str, 2);
	ft_putnbr_fd(num, 2);
}

static void	ps_print_strategy(t_config *config)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(config->strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(config->symbol, 2);
	ft_putstr_fd("\n", 2);
}

void	ps_print_bench(t_config *config)
{
	ps_print_disorder(config->disorder);
	ps_print_strategy(config);
	ps_putstr_num("[bench] total_ops: ", ps_cal_total_ops(config));
	ps_putstr_num("\n[bench] sa: ", config->sa);
	ps_putstr_num(" sb: ", config->sb);
	ps_putstr_num(" ss: ", config->ss);
	ps_putstr_num(" pa: ", config->pa);
	ps_putstr_num(" pb: ", config->pb);
	ps_putstr_num("\n[bench] ra: ", config->ra);
	ps_putstr_num(" rb: ", config->rb);
	ps_putstr_num(" rr: ", config->rr);
	ps_putstr_num(" rra: ", config->rra);
	ps_putstr_num(" rrb: ", config->rrb);
	ps_putstr_num(" rrr: ", config->rrr);
	ft_putstr_fd("\n", 2);
}
