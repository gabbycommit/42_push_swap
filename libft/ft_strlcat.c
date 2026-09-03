/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:33:59 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 15:32:03 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (size > dst_len && dst[dst_len])
		dst_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (size - 1 > dst_len + i && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	// system
	printf("System: --\n");
	char	d1[20] = "hello";
	char	d2[6] = "hello";
	char	d5[0];
	char	*s1 = " world";
	printf("--- Before: ---\n");
	printf("d1: %s\n", d1);
	printf("d2: %s\n", d2);
	printf("s1: %s\n", s1);
	printf("--- After: ---\n");
	size_t	len1 = strlcat(d1, s1, 20);
	size_t	len2 = strlcat(d2, s1, 6);
	size_t	len5 = strlcat(d5, s1, 0);
	printf("d1 -- size=20: %s; return value: %ld\n", d1, len1);
	printf("d2 -- size=6: %s; return value: %ld\n", d2, len2);
	printf("d5 -- size=0: %s; return value: %ld\n", d5, len5);

	// ft
	printf("\nft: --\n");
	char	d3[20] = "hello";
	char	d4[6] = "hello";
	char	d6[0];
	printf("--- Before: ---\n");
	printf("d3: %s\n", d3);
	printf("d4: %s\n", d4);
	printf("s1: %s\n", s1);
	printf("--- After: ---\n");
	size_t	len3 = ft_strlcat(d3, s1, 20);
	size_t	len4 = ft_strlcat(d4, s1, 6);
	size_t	len6 = ft_strlcat(d6, s1, 0);
	printf("d3 -- size=20: %s; return value: %ld\n", d3, len3);
	printf("d4 -- size=6: %s; return value: %ld\n", d4, len4);
	printf("d6 -- size=0: %s; return value: %ld\n", d6, len6);
	return (0);	
}
*/
