/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:19:11 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 15:46:41 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>

char *strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	const char	*big = "Foo Bar Baz";
	const char	*little1 = "Bar";
	const char	*little2 = "";
	const char	*little3 = "42";
	
	// system
	printf("System: --\n");
	printf("Big: %s\n", big);
	printf("Little: %s\n", little1);
	printf("Result: %p\n", strnstr(big, little1, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little2);
	printf("Result: %p\n", strnstr(big, little2, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little3);
	printf("Result: %p\n", strnstr(big, little3, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little1);
	printf("Result -- len=3: %p\n", strnstr(big, little1, 3));

	// ft
	printf("\nft: --\n");
	printf("Big: %s\n", big);
	printf("Little: %s\n", little1);
	printf("Result: %p\n", ft_strnstr(big, little1, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little2);
	printf("Result: %p\n", ft_strnstr(big, little2, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little3);
	printf("Result: %p\n", ft_strnstr(big, little3, strlen(big)));
	printf("-----------\nBig: %s\n", big);
	printf("Little: %s\n", little1);
	printf("Result -- len=3: %p\n", ft_strnstr(big, little1, 3));
	return (0);
}
*/
