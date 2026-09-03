/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:55:03 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 14:36:04 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	// system
	printf("System: --\n");
	char	d1[6];
	char	d2[5];
	char	*s1 = "Hello";
	printf("Src: %s\n", s1);
	strlcpy(d1, s1, 6);
	strlcpy(d2, s1, 5);
	printf("Size=6: %s\n", d1);
	printf("Size=5: %s\n", d2);

	// ft
	printf("\nft: --\n");
	char	d3[6];
	char	d4[5];
	printf("Src: %s\n", s1);
	ft_strlcpy(d3, s1, 6);
	ft_strlcpy(d4, s1, 5);
	printf("Size=6: %s\n", d1);
	printf("Size=5: %s\n", d2);
	return (0);
}
*/
