/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:10:07 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:54:09 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_stack	*ps_new_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last_node;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		return ;
	}
	last_node = ps_lstlast(*lst);
	last_node->next = new_node;
	new_node->prev = last_node;
}

void	ps_lstadd_front(t_stack **lst, t_stack *new_node)
{
	t_stack	*second;

	if (!lst || !new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		return ;
	}
	second = (*lst)->next;
	new_node->prev = NULL;
	new_node->next = *lst;
	(*lst)->prev = new_node;
	if (second)
	{
		(*lst)->next = second;
		second->prev = *lst;
	}
	else
		(*lst)->next = NULL;
	*lst = new_node;
}
