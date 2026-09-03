/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:51:46 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 15:19:26 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
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
	printf("Testing find '4': %p\n", strrchr(s, '4'));
	printf("Testing find '\\0': %p\n", strrchr(s, '\0'));
	printf("Testing find 'P': %p\n", strrchr(s, 'P'));
	printf("Testing find 'l': %p\n", strrchr(s, 'l'));
	printf("\nft: --\n");
	printf("string: %s\n", s);
	printf("Testing find '4': %p\n", ft_strrchr(s, '4'));
	printf("Testing find '\\0': %p\n", ft_strrchr(s, '\0'));
	printf("Testing find 'P': %p\n", ft_strrchr(s, 'P'));
	printf("Testing find 'l': %p\n", ft_strrchr(s, 'l'));
	return (0);
}
*/
