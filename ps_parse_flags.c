/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:14:07 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/03 16:51:05 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_is_flags(const char *s, t_counter *count)
{
	if (ft_strncmp(s, "--simple", 9) == 0)
		return (count->strategy = "--simple", 1);
	if (ft_strncmp(s, "--medium", 9) == 0)
		return (count->strategy = "--medium", 1);
	if (ft_strncmp(s, "--complex", 10) == 0)
		return (count->strategy = "--complex", 1);
	if (ft_strncmp(s, "--adaptive", 11) == 0)
		return (count->strategy = "--adaptive", 1);
	if (ft_strncmp(s, "--bench", 8) == 0)
		return (count->bench = 1, 1);
	return (0);
}

char	**ps_filter_flags(int argc, char **argv, t_counter *count)
{
	char	**num_data;
	int		i;
	int		j;

	num_data = (char **)malloc(sizeof(char *) * argc);
	if (!num_data)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!ps_is_flags(argv[i], count))
		{
			num_data[j] = argv[i];
			j++;
		}
		i++;
	}
	num_data[j] = NULL;
	return (num_data);
}
