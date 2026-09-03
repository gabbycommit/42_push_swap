/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:43:01 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/02 11:46:17 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Allocates memory (using malloc(3)) and returns a
 * 	substring from the string ’s’.
 *	The substring starts at index ’start’ and has a
 *	maximum length of ’len’.
 *
 *	RETURN:
 *		- The substring.
 *		- NULL if the allocation fails.
 *
 *	*NOTE:
 *		- if 'start' is >= length of 's', an empty str is return.
 *		- Ensure s[len] not overflow.
 *		- Handle s = NULL, return NULL 
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(s[0]) * (len + 1));
	if (!substr)
		return (NULL);
	ft_memmove(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*sub1;
	char	*sub2;
	char	*sub3;
	char	*sub4;
	char	*s = "hello, 42 !";

	sub1 = ft_substr(s, 0, strlen(s));
	sub2 = ft_substr(s, strlen(s) + 1, strlen(s));
	sub3 = ft_substr(s, 0, strlen(s) + 10);
	sub4 = ft_substr(NULL, 0, 10);
	printf("String: %s\n", s);
	printf("\n--- Testing normal substr ---\n");
	printf("Result: %s\n", sub1);
	printf("\n--- Testing start <= len of s ---\n");
	printf("Result: %s\n", sub2);
	printf("\n--- Testing len > s_len - start ---\n");
	printf("Result: %s\n", sub3);
	printf("\n--- Testing s = NUll ---\n");
	printf("Result: %s\n", sub4);

	free(sub1);
	free(sub2);
	free(sub3);
}
*/
