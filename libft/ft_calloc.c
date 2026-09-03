/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:01:27 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 16:02:55 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (size != 0 && (total / size) != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <string.h>
#include <stdio.h>

void	print_ascii(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		printf("[%d] ", s[i]);
		i++;
	}
}

int	main(void)
{
	const char	*s = "hello 42";
	char		*result1;
	char		*result3;
	char		*result4;
	size_t		len;

	len = strlen(s);
	result1 = calloc(len, sizeof(s[0]));
	if (!result1)
		return (1);
	printf("System: --\n");
	printf("Normal allocate:\n");
	print_ascii(result1, len);
	

	printf("\n\nft: ---\n");
	result3 = ft_calloc(len, sizeof(s[0]));
	if (!result3)
		return (1);
	print_ascii(result3, len);
	printf("\nTesting nmemb=0: test with valgrind/fsanitize\n");
	result4 = ft_calloc(0, sizeof(s[0]));
	if (!result4)
		return (1);

	free(result1);
	free(result3);
	free(result4);
	return (0);
}
*/
