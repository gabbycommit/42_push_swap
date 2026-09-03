/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:49:03 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 17:10:54 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include "string.h"
#include "stdio.h"

void	print_ascii(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("[%d] ", s[i]);
		i++;
	}
}

int	main(void)
{
	// system
	printf("System: ---\n");
	char	s1[] = "Hello 42";
	printf("Origin:\n");
	printf("%s\n", s1);
	printf("Ascii: ");
	print_ascii(s1, 8);
	bzero(s1, 5);
	printf("\nAfter bzero:");
	print_ascii(s1, 8);

	// ft
	printf("\n\nft: ---\n");
	char	s2[] = "Hello 42";
	printf("Origin:\n");
	printf("%s\n", s2);
	printf("Ascii: ");
	print_ascii(s2, 8);
	bzero(s2, 5);
	printf("\nAfter bzero:");
	print_ascii(s2, 8);
	return (0);
}
*/
