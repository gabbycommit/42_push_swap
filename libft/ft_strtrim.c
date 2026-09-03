/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:40:18 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/02 16:47:25 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	DESCRIPTION:
 *		Allocates memory (using malloc(3)) and returns a
 *		copy of ’s1’ with characters from ’set’ removed
 *		from the beginning and the end.
 *
 *	RETURN:
 *		The trimmed string.
 *		NULL if the allocation fails.
 *
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	result = ft_substr(s1, start, end - start + 1);
	if (!result)
		return (NULL);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "   hello world!   ";
	const char	*set = " h!d";
	char *result = ft_strtrim(s, set);
	if (!result)
		return (1);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
