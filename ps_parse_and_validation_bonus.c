/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_and_validation_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:36:26 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 17:45:00 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

// only digit, int, no repeat
static int	ps_is_valid(const char *s, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	num = ps_atol(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	while (a)
	{
		if (a->num == num)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	ps_free_all(t_stack *a, char **splitted, int i)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static int	ps_process_validate_and_stack(char **splitted, t_stack **a)
{
	int		i;
	int		num;
	t_stack	*new_node;

	i = 0;
	while (splitted[i])
	{
		if (ps_is_valid(splitted[i], *a))
		{
			num = (int)ps_atol(splitted[i]);
			new_node = ps_new_node(num);
			if (!new_node)
				return (ps_free_all(*a, splitted, i), 0);
			ps_lstadd_back(a, new_node);
			free(splitted[i]);
		}
		else
			return (ps_free_all(*a, splitted, i), 0);
		i++;
	}
	free(splitted);
	return (1);
}

t_stack	*ps_parse_and_validation(char **argv)
{
	int		i;
	char	**splitted;
	t_stack	*a;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			return (ps_free_all(a, NULL, 0), NULL);
		if (!splitted[0])
			return (ps_free_all(a, splitted, 0), NULL);
		if (!ps_process_validate_and_stack(splitted, &a))
			return (NULL);
		i++;
	}
	return (a);
}
