/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:06:38 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 18:17:19 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "helLo 42";
	const char	*s2 = "hello 42";
	const char	*s3 = "penang is the best";
	const char	*s4 = "";

	// system
	printf("System: --\n");
	printf("Comparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", strncmp(s1, s2, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", strncmp(s1, s2, 3));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s3: %s\n", s3);
	printf("Result = %d\n", strncmp(s1, s3, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s4: %s\n", s4);
	printf("Result = %d\n", strncmp(s1, s4, strlen(s1)));

	// ft
	printf("\nft: --\n");
	printf("Comparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", ft_strncmp(s1, s2, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", ft_strncmp(s1, s2, 3));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s3: %s\n", s3);
	printf("Result = %d\n", ft_strncmp(s1, s3, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s4: %s\n", s4);
	printf("Result = %d\n", ft_strncmp(s1, s4, strlen(s1)));
	return (0);
}
*/
