/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:03:25 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 16:10:06 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("System: ---\n");
	printf("The length of 'Hello': %ld\n", strlen("Hello"));
	printf("ft: ---\n");
	printf("The length of 'Hello': %ld\n", ft_strlen("Hello"));
	return (0);
}
*/
