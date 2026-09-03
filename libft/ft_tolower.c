/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:55:18 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 15:58:46 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("System: --\n");
	printf("Testing 'a': %c\n", tolower('a'));
	printf("Testing ';': %c\n", tolower(';'));
	printf("Testing 'A': %c\n", tolower('A'));
	printf("Testing '0': %c\n", tolower('0'));
	printf("\nft: --\n");
	printf("Testing 'a': %c\n", ft_tolower('a'));
	printf("Testing ';': %c\n", ft_tolower(';'));
	printf("Testing 'A': %c\n", ft_tolower('A'));
	printf("Testing '0': %c\n", ft_tolower('0'));
	return (0);
}
*/
