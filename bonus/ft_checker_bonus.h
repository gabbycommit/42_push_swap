/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:05:21 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/27 12:04:59 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// operations
void	ps_push_a(t_stack **a, t_stack **b);
void	ps_push_b(t_stack **a, t_stack **b);
void	ps_swap_a(t_stack **a);
void	ps_swap_b(t_stack **b);
void	ps_ss(t_stack **a, t_stack **b);
void	ps_rotate_a(t_stack **a);
void	ps_rotate_b(t_stack **b);
void	ps_rr(t_stack **a, t_stack **b);
void	ps_reverse_rotate_a(t_stack **a);
void	ps_reverse_rotate_b(t_stack **b);
void	ps_rrr(t_stack **a, t_stack **b);

// utils
t_stack	*ps_new_node(int num);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_back(t_stack **lst, t_stack *new_node);
void	ps_lstadd_front(t_stack **lst, t_stack *new_node);
long	ps_atol(const char *s);

// parse and validation
t_stack	*ps_parse_and_validation(char **argv);

// exec ops
char	*get_next_line(int fd);
int		ps_exec_ops(int fd, t_stack **a, t_stack **b);

#endif
