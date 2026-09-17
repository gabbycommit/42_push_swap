/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:42:11 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/17 09:21:27 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// for benchmark use, for calculating the operations
typedef struct s_config
{
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	float		disorder;
	int			bench;
	char		*strategy;
	char		*symbol;
}				t_config;

// using two-way linked list as stack a
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// utils
t_stack		*ps_new_node(int num);
void		ps_lstadd_back(t_stack **lst, t_stack *new_node);
void		ps_lstadd_front(t_stack **lst, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *lst);
size_t		ps_lstcount(t_stack *lst);
long		ps_atol(const char *s);
float		ps_compute_disorder(t_stack *a);

// parse and validation, bench
t_stack		*ps_parse_and_validation(int argc, char **argv, t_config *config);
void		ps_compute_disorder_and_symbol(t_stack *a, t_config *config);
void		ps_print_bench(t_config *config);

// operations
void		ps_swap_a(t_stack **a, t_config *config, int is_write);
void		ps_swap_b(t_stack **b, t_config *config, int is_write);
void		ps_ss(t_stack **a, t_stack **b, t_config *config);
void		ps_push_a(t_stack **a, t_stack **b, t_config *config);
void		ps_push_b(t_stack **a, t_stack **b, t_config *config);
void		ps_rotate_a(t_stack **a, t_config *config, int is_write);
void		ps_rotate_b(t_stack **b, t_config *config, int is_write);
void		ps_rr(t_stack **a, t_stack **b, t_config *config);
void		ps_reverse_rotate_a(t_stack **a, t_config *config, int is_write);
void		ps_reverse_rotate_b(t_stack **b, t_config *config, int is_write);
void		ps_rrr(t_stack **a, t_stack **b, t_config *config);

// algo
void		ps_init_rank(t_stack *a);

#endif
