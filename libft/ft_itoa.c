/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:35:43 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 15:15:13 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Allocates memory (using malloc(3)) and returns
 *		a string representing the integer received as an
 *		argument. Negative numbers must be handled.
 *
 *	RETURN:
 *		The string representing the integer.
 *		NULL if the allocation fails.
 */

static size_t	char_count(long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	size_t	len;
	size_t	i;

	nb = n;
	len = char_count(nb);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		i = 1;
		result[0] = '-';
		nb = -nb;
	}
	result[len] = '\0';
	while (i < len--)
	{
		result[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result1 = ft_itoa(2147483647);
	if (!result1)
		return (1);
	printf("Testing INT_MAX: %s\n", result1);
	free(result1);
	
	char	*result2 = ft_itoa(-2147483648);
	if (!result2)
		return (1);
	printf("Testing INT_MAX: %s\n", result2);
	free(result2);
	
	char	*result3 = ft_itoa(0);
	if (!result3)
		return (1);
	printf("Testing 0: %s\n", result3);
	free(result3);
	return (0);
}
*/
