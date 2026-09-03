/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:01:36 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 17:06:05 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp_s;
	size_t				i;

	temp_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == (unsigned char)c)
			return ((void *)(temp_s + i));
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*s = "hello 42";
	printf("System: --\n");
	printf("string: %s\n", s);
	printf("Testing find '4': %p\n", memchr(s, '4', strlen(s) + 1));
	printf("Testing find '\\0': %p\n", memchr(s, '\0', strlen(s) + 1));
	printf("Testing find 'P': %p\n", memchr(s, 'P', strlen(s) + 1));
	printf("\nft: --\n");
	printf("string: %s\n", s);
	printf("Testing find '4': %p\n", ft_memchr(s, '4', strlen(s) + 1));
	printf("Testing find '\\0': %p\n", ft_memchr(s, '\0', strlen(s) + 1));
	printf("Testing find 'P': %p\n", ft_memchr(s, 'P', strlen(s) + 1));
	return (0);
}
*/
