/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:17:13 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/31 17:31:14 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = sizeof(s[0]) * (ft_strlen(s) + 1);
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, size);
	return (dup);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "hello 42!!";
	char	*result1;
	char	*result2;

	result1 = strdup(s);
	if (!result1)
		return (1);
	result2 = ft_strdup(s);
	if (!result2)
		return (1);

	printf("String: %s\n", s);
	printf("\nSystem: --\n");
	printf("Result: %s\n", result1);	
	printf("\nft: --\n");
	printf("Result: %s\n", result2);
	free(result1);
	free(result2);
	return(0);
}
*/
