/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_and_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:36:37 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/27 16:00:36 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char	**ps_filter_flags(int argc, char **argv, t_config *config)
{
	char	**argv_without_flags;
	int		j;

	argv_without_flags = (char **)malloc(sizeof(char *) * argc);
	if (!argv_without_flags)
		return (NULL);
	j = 0;
	argv++;
	while (argc-- > 1)
	{
		if (ft_strncmp(*argv, "--simple", 9) == 0)
			config->strategy = "Simple";
		else if (ft_strncmp(*argv, "--medium", 9) == 0)
			config->strategy = "Medium";
		else if (ft_strncmp(*argv, "--complex", 10) == 0)
			config->strategy = "Complex";
		else if (ft_strncmp(*argv, "--adaptive", 11) == 0)
			config->strategy = "Adaptive";
		else if (ft_strncmp(*argv, "--bench", 8) == 0)
			config->bench = 1;
		else
			argv_without_flags[j++] = *argv;
		argv++;
	}
	return (argv_without_flags[j] = NULL, argv_without_flags);
}

static int	ps_is_valid_input(char *s, t_stack *a)
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
		if (num == a->num)
			return (0);
		a = a->next;
	}
	return (1);
}

static t_stack	*ps_free_all_and_null(
	char **argv_without_flags, char **splitted, int *i, t_stack *a)
{
	t_stack	*temp;

	if (argv_without_flags)
		free(argv_without_flags);
	if (splitted)
	{
		while (splitted[*i])
		{
			free(splitted[*i]);
			(*i)++;
		}
		free(splitted);
	}
	if (a)
	{
		while (a)
		{
			temp = a->next;
			free(a);
			a = temp;
		}
	}
	return (NULL);
}

static t_stack	*ps_num_parse_and_validation(
	char **argv_without_flags, char **splitted, t_stack *a)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	if (!splitted[i])
		return (ps_free_all_and_null(argv_without_flags, splitted, &i, a));
	while (splitted[i])
	{
		if (!ps_is_valid_input(splitted[i], a))
			return (ps_free_all_and_null(argv_without_flags, splitted, &i, a));
		new_node = ps_new_node((int)ps_atol(splitted[i]));
		if (!new_node)
			return (ps_free_all_and_null(argv_without_flags, splitted, &i, a));
		ps_lstadd_back(&a, new_node);
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (a);
}

t_stack	*ps_parse_and_validation(int argc, char **argv, t_config *config)
{
	t_stack	*a;
	char	**argv_without_flags;
	char	**splitted;
	int		i;

	argv_without_flags = ps_filter_flags(argc, argv, config);
	if (!argv_without_flags)
		return (NULL);
	i = 0;
	a = NULL;
	while (argv_without_flags[i])
	{
		splitted = ft_split(argv_without_flags[i], ' ');
		if (!splitted)
			return (ps_free_all_and_null(argv_without_flags, NULL, NULL, a));
		a = ps_num_parse_and_validation(argv_without_flags, splitted, a);
		if (!a)
			return (NULL);
		i++;
	}
	free(argv_without_flags);
	return (a);
}
