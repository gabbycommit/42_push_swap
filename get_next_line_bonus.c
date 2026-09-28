/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 09:36:06 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/28 16:13:47 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static ssize_t	ft_strchr_idx(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*free_and_null(char *buf, char **stack)
{
	if (buf)
		free(buf);
	if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
	return (NULL);
}

static char	*read_and_stack(int fd, char *stack)
{
	char	*buf;
	char	*ori;
	ssize_t	bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr_idx(stack, '\n') == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null(buf, &stack));
		buf[bytes_read] = '\0';
		ori = stack;
		stack = ft_strjoin(stack, buf);
		if (!stack)
			return (free_and_null(buf, &ori));
		free(ori);
	}
	free(buf);
	return (stack);
}

static char	*get_line(char **stack)
{
	char	*result;
	char	*ori;
	ssize_t	idx_nl;

	if (!(*stack) || !((*stack)[0]))
		return (free_and_null(NULL, stack));
	idx_nl = ft_strchr_idx(*stack, '\n');
	if (idx_nl >= 0)
	{
		result = ft_substr(*stack, 0, idx_nl + 1);
		ori = *stack;
		if ((*stack)[idx_nl + 1] != '\0')
			*stack = ft_substr(
					*stack, idx_nl + 1, ft_strlen(*stack) - idx_nl - 1);
		else
			*stack = NULL;
		free(ori);
	}
	else
	{
		result = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack)
		stack = ft_strdup("");
	if (!stack)
		return (NULL);
	stack = read_and_stack(fd, stack);
	if (!stack)
		return (NULL);
	return (get_line(&stack));
}
