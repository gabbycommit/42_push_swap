/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_and_validation_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:36:26 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/23 17:06:54 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

// only digit, only int, no repeat
static int	ps_is_valid(const char *s, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	num = ft_atol(s);
	if (num > 2147483647 || num < -2147483648)
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
	a = NULL;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static void	ps_process_validate_and_stack(char **splitted, t_stack **a)
{
	int		i;
	int		num;
	t_stack	*new_node;

	i = 0;
	while (splitted[i])
	{
		if (ps_is_valid(splitted[i]))
		{
			num = ft_atoi(splitted[i]);
			new_node = ps_new_node(num);
			ps_lstadd_back(a, new_node);
			free(splitted[i]);
		}
		else
		{
			ps_free_all(*a, splitted, i);
			return ;
		}
		i++:
	}
	free(splitted);
}

t_stack	*ps_parse_and_validation(char **agrv)
{
	int		i;
	char	*splitted;
	t_stack *a;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		splitted = ft_split(argv[i], ' ');
		if (!splitted)
			return (NULL);
		ps_process_validate_and_stack(splitted, &a);
		i++;
	}
	return (a);
}
