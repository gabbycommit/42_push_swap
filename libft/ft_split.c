/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:06:34 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 12:59:17 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Allocates memory (using malloc(3)) and returns an
 *		array of strings obtained by splitting ’s’ using
 *		the character ’c’ as a delimiter.
 *		Each string in the returned array is allocated
 *		independently.
 *		The array of pointers itself is also allocated
 *		dynamically.
 *		The returned array must be NULL terminated.
 *
 *	RETURN:
 *		The array of new strings resulting from the split.
 *		NULL if any allocation fails.
 *		The returned structure will be released using: 1)
 *		free() on each string in the array; 2) free() the
 *		array itself.
 */

static size_t	word_count(char const *s, char c)
{
	size_t				i;
	size_t				count;
	unsigned int		new_word;

	i = 0;
	count = 0;
	new_word = 1;
	while (s[i])
	{
		if (s[i] != c && new_word)
		{
			count++;
			new_word = 0;
		}
		if (s[i] == c && !new_word)
			new_word = 1;
		i++;
	}
	return (count);
}

static void	ft_free(char **s_arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(s_arr[i]);
	}
	free(s_arr);
}

static int	splitting_words(
	char const *s, char c, char **result, size_t total_words)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (i < total_words)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = ft_substr(s, start, end - start);
		if (!result[i])
		{
			ft_free(result, i);
			return (0);
		}
		i++;
		start = end;
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	total_words;

	if (!s)
		return (NULL);
	total_words = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!result)
		return (NULL);
	if (!splitting_words(s, c, result, total_words))
		return (NULL);
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**result = ft_split("   v   hello this   is  42   ", ' ');
	if (!result)
		return (1);
	
	size_t	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/
