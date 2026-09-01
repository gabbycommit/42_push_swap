/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:42:11 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/30 19:00:46 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>

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
void		ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ps_lstlast(t_stack *lst);

#endif
