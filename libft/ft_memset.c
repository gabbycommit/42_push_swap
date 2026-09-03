/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:12:52 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 16:44:06 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	// system
	printf("System: ---\n");
	char	s_system[] = "hello, world";
	printf("Origin = %s\n", s_system);
	memset(s_system, '0', 5);
	printf("Afer memset: %s\n", s_system);
	// ft
	printf("\nft: ---\n");
	char	s_ft[] = "hello, world";
	printf("Origin: %s\n", s_ft);
	ft_memset(s_ft, '0', 5);
	printf("After ft_memset: %s\n", s_ft);
	return (0);
}
*/
