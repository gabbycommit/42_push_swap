/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:09:28 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/31 12:01:09 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;
	size_t				i;

	if (n == 0)
		return (0);
	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
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
	const char	*s3 = "penang";
	const char	*s4 = "";

	// system
	printf("System: --\n");
	printf("Comparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", memcmp(s1, s2, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", memcmp(s1, s2, 3));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s3: %s\n", s3);
	printf("Result = %d\n", memcmp(s1, s3, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s4: %s\n", s4);
	printf("Result = %d\n", memcmp(s1, s4, strlen(s1)));

	// ft
	printf("\nft: --\n");
	printf("Comparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", ft_memcmp(s1, s2, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("Result = %d\n", ft_memcmp(s1, s2, 3));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s3: %s\n", s3);
	printf("Result = %d\n", ft_memcmp(s1, s3, strlen(s1)));
	printf("-----\nComparing:\ns1: %s\n", s1);
	printf("s4: %s\n", s4);
	printf("Result = %d\n", ft_memcmp(s1, s4, strlen(s1)));
	return (0);
}
*/
