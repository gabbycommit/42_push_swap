/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:15:56 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/04 15:36:41 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Applies the function f to each character of the
 *		string s, passing its index as the first argument
 *		and the character itself as the second. A new
 *		string is created (using malloc(3)) to store the
 *		results from the successive applications of f.
 *
 *	RETURN:
 *		The string created from the successive applications
 *		of ’f’.
 *		Returns NULL if the allocation fails.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <ctype.h>

char	test_function(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper((unsigned char)c));
	return (tolower((unsigned char)c));
}

int	main(void)
{
	char const	*s = "hello, 42";
	char		*result;

	result = ft_strmapi(s, test_function);
	printf("Original str: %s\n", s);
	printf("strmapi str: %s\n", result);
	free(result);
	return (0);
}
*/
