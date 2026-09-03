/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:32:20 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 18:29:49 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	memcpy copies n bytes from memory area src to memory area dest.
	However it skipped safety checking:

	- No overlap check.
	- No bounds check.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	if (!dest && !src)
		return (dest);
	temp_d = (unsigned char *)dest;
	temp_s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_d[i] = temp_s[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	// system
	char	*src1 = "hello";
	char	dest1[6];
	printf("System: ---\n");
	printf("Before: %s\n", dest1);
	memcpy(dest1, src1, 6);
	printf("After: %s\n", dest1);

	// ft
	char	*src2 = "hello";
	char	dest2[6];
	printf("\nft: ---\n");
	printf("Before: %s\n", dest2);
	ft_memcpy(dest2, src2, 6);
	printf("After: %s\n", dest2);
	return (0);
}
*/
