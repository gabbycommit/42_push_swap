/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:47:13 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/02 14:38:48 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	DESCRIPTION:
 *		Allocates memory (using malloc(3)) and returns a
 *		new string, which is the result of concatenating
 *		’s1’ and ’s2’.
 *
 *	RETURN:
 *		The new string.
 *		NULL if the allocation fails.
 *
 *	NOTE:
 *		- if s1 || s2 == NULL, return NULL.
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(s1[0]) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "hello ";
	const char	*s2 = "world!!!";
	char		*result1;
	char		*result2;
	char		*result3;
	char		*result4;

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("\n--- Testing normal strjoin ---\n");
	
	result1 = ft_strjoin(s1, s2);
	if (!result1)
		return (1);
	printf("Result1: %s\n", result1);
	free(result1);

	printf("\n--- Testing s1 = "" ---\n");
	result2 = ft_strjoin("", s2);
	if (!result2)
		return (1);
	printf("Result2: %s\n", result2);
	free(result2);

	printf("\n--- Testing s2 = "" ---\n");
	result3 = ft_strjoin(s1, "");
	if (!result3)
		return (1);
	printf("Result3: %s\n", result3);
	free(result3);

	printf("\n--- Testing s1 = NULL ---\n");
	result4 = ft_strjoin(NULL, s2);
	if (!result4)
		return (1);
	printf("Result4: %s\n", result4);
	free(result4);
	return (0);
}
*/
