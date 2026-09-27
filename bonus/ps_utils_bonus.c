/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:10:07 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/26 15:07:49 by hukhaw           ###   ########.fr       */
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

long	ps_atol(const char *s)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
