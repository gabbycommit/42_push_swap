/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:42:11 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/01 16:02:29 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// for benchmark use, for calculating the operations
typedef struct s_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
}		t_counter;

// using two-way linked list as stack a
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack		*ps_new_node(int num);
t_counter	*ps_new_counter(void);
void		ps_lstadd_back(t_stack **lst, t_stack *new_node);
void		ps_lstadd_front(t_stack **lst, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *lst);
size_t		ps_lstcount(t_stack *lst);
void		ps_swap_a(t_stack **a, t_counter *count, int is_write);
void		ps_swap_b(t_stack **b, t_counter *count, int is_write);
void		ps_ss(t_stack **a, t_stack **b, t_counter *count);
void		ps_push_a(t_stack **a, t_stack **b, t_counter *count);
void		ps_push_b(t_stack **a, t_stack **b, t_counter *count);
void		ps_rotate_a(t_stack **a, t_counter *count, int is_write);
void		ps_rotate_b(t_stack **b, t_counter *count, int is_write);
void		ps_rr(t_stack **a, t_stack **b, t_counter *count);
void		ps_reverse_rotate_a(t_stack **a, t_counter *count, int is_write);
void		ps_reverse_rotate_b(t_stack **b, t_counter *count, int is_write);
void		ps_rrr(t_stack **a, t_stack **b, t_counter *count);

#endif
