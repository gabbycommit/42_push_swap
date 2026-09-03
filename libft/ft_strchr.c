/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:59:24 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 17:05:38 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen(s) + 1;
	return ((char *)ft_memchr(s, c, n));
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char	*s = "hello 42";
	printf("System: --\n");
	printf("string: %s\n", s);
	printf("Testing find '4': %p\n", strchr(s, '4'));
	printf("Testing find '\\0': %p\n", strchr(s, '\0'));
	printf("Testing find 'P': %p\n", strchr(s, 'P'));
	printf("Testing find 'l': %p\n", strchr(s, 'l'));
	printf("\nft: --\n");
	printf("string: %s\n", s);
	printf("Testing find '4': %p\n", ft_strchr(s, '4'));
	printf("Testing find '\\0': %p\n", ft_strchr(s, '\0'));
	printf("Testing find 'P': %p\n", ft_strchr(s, 'P'));
	printf("Testing find 'l': %p\n", ft_strchr(s, 'l'));
	return (0);
}
*/
