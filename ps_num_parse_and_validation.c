/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:37:01 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/03 16:42:44 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_is_valid_input(char *s, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	num = ps_atol(s);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	while (a)
	{
		if (num == a->num)
			return (0);
		a = a->next;
	}
	return (1);
}

static t_stack	*ps_free_all_and_null(
	t_stack *a, char **splitted, char **num_data)
{
	t_stack	*next;
	int		i;

	while (a)
	{
		next = a->next;
		free(a);
		a = next;
	}
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	free(num_data);
	return (NULL);
}

static void	ps_free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static t_stack	*ps_parse_num(char **splitted, char **num_data, t_stack **a)
{
	int		j;
	t_stack	*new_node;

	j = 0;
	while (splitted[j])
	{
		if (!ps_is_valid_input(splitted[j], *a))
			return (ps_free_all_and_null(*a, splitted, num_data));
		new_node = ps_new_node(ft_atoi(splitted[j]));
		if (!new_node)
			return (ps_free_all_and_null(*a, splitted, num_data));
		ps_lstadd_back(a, new_node);
		j++;
	}
	ps_free_splitted(splitted);
	return (*a);
}

t_stack	*ps_num_parse_and_validation(char **num_data, t_stack **a)
{
	int		i;
	char	**splitted;

	i = 0;
	while (num_data[i])
	{
		splitted = ft_split(num_data[i], ' ');
		if (!splitted)
		{
			free(num_data);
			return (NULL);
		}
		*a = ps_parse_num(splitted, num_data, a);
		i++;
	}
	free(num_data);
	return (*a);
}
