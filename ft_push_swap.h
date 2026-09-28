/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:42:11 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:27:39 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
	double		disorder;
	int			bench;
	char		*strategy;
	char		*symbol;
}				t_config;

// using two-way linked list as stack a
typedef struct s_stack
{
	int				num;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_move
{
	int	a;
	int	b;
	int	cost;
}		t_move;

typedef struct s_chunk
{
	int	size;
	int	pushed;
	int	pending_to_rb;
}		t_chunk;

// utils
t_stack		*ps_new_node(int num);
void		ps_lstadd_back(t_stack **lst, t_stack *new_node);
void		ps_lstadd_front(t_stack **lst, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *lst);
int			ps_lstcount(t_stack *lst);
long		ps_atol(const char *s);
double		ps_compute_disorder(t_stack *a);

// parse and validation, bench
t_stack		*ps_parse_and_validation(int argc, char **argv, t_config *config);
void		ps_compute_disorder_and_symbol(t_stack *a, t_config *config);
void		ps_print_bench(t_config *config);

// operations
void		ps_swap_a(t_stack **a, t_config *config);
void		ps_swap_b(t_stack **b, t_config *config);
void		ps_ss(t_stack **a, t_stack **b, t_config *config);
void		ps_push_a(t_stack **a, t_stack **b, t_config *config);
void		ps_push_b(t_stack **a, t_stack **b, t_config *config);
void		ps_rotate_a(t_stack **a, t_config *config);
void		ps_rotate_b(t_stack **b, t_config *config);
void		ps_rr(t_stack **a, t_stack **b, t_config *config);
void		ps_reverse_rotate_a(t_stack **a, t_config *config);
void		ps_reverse_rotate_b(t_stack **b, t_config *config);
void		ps_rrr(t_stack **a, t_stack **b, t_config *config);

// sort utils
void		ps_init_rank(t_stack *a);
void		ps_sort_small(t_stack **a, t_config *config);
int			ps_is_sorted(t_stack *a);

// simple sort
int			ps_signed_moves_to_top(int idx, int size);
int			ps_total_cost(int a, int b);
int			ps_max_idx(t_stack *lst);
int			ps_target_idx_b(t_stack *b, int rank);
void		ps_rot_a(int n, t_stack **a, t_config *config);
void		ps_rot_b(int n, t_stack **b, t_config *config);
void		ps_exec_move(t_move *m, t_stack **a, t_stack **b, t_config *config);
void		ps_simple_sort(t_stack **a, t_stack **b, t_config *config);

// medium sort
int			ps_isqrt(int n);
int			ps_chunk_size(int n);
void		ps_rot_a_dir(int idx, int size, t_stack **a, t_config *config);
void		ps_rot_b_dir(int idx, int size, t_stack **b, t_config *config);
void		ps_push_chunks(t_stack **a, t_stack **b, t_config *config, int n);
void		ps_pull_back(t_stack **a, t_stack **b, t_config *config);
void		ps_medium_sort(t_stack **a, t_stack **b, t_config *config);

// complex sort
int			ps_get_pivot(t_stack *stack, int size);
void		ps_complex_sort_two(t_stack **stack, t_config *config, int is_a);
void		ps_restore(
				t_stack **stack, t_config *config, int rotate_count, int is_a);
void		ps_complex_quick_sort(t_stack **a, t_stack **b, t_config *config);

#endif
