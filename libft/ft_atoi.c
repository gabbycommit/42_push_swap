/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:01:53 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/31 15:59:26 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	printf("System: ---\n");
	printf("Testing '    01923': %d\n", atoi("    01923"));
	printf("Testing INT_MAX: %d\n", atoi("2147483647"));
	printf("Tesing INT_MIN: %d\n", atoi("-2147483648"));
	printf("Testing '+652': %d\n", atoi("+652"));
	printf("Testing '-652': %d\n", atoi("-652"));
	printf("Testing '  +652': %d\n", atoi("  +652"));
	printf("Testing '  -652': %d\n", atoi("  -652"));
	printf("Testing 'abc652': %d\n", atoi("abc652"));
	printf("Testing '65cs2': %d\n", atoi("abc65cs2"));

	// ft
	printf("ft: \n---\n");
	printf("Testing '    01923': %d\n", ft_atoi("    01923"));
	printf("Testing INT_MAX: %d\n", ft_atoi("2147483647"));
	printf("Tesing INT_MIN: %d\n", ft_atoi("-2147483648"));
	printf("Testing '+652': %d\n", ft_atoi("+652"));
	printf("Testing '-652': %d\n", ft_atoi("-652"));
	printf("Testing '  +652': %d\n", ft_atoi("  +652"));
	printf("Testing '  -652': %d\n", ft_atoi("  -652"));
	printf("Testing 'abc652': %d\n", ft_atoi("abc652"));
	printf("Testing '65cs2': %d\n", ft_atoi("abc65cs2"));
	return (0);
}
*/
