/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:49:49 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/30 15:54:45 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("System: --\n");
	printf("Testing 'a': %c\n", toupper('a'));
	printf("Testing ';': %c\n", toupper(';'));
	printf("Testing 'A': %c\n", toupper('A'));
	printf("Testing '0': %c\n", toupper('0'));

	printf("\nft: --\n");
	printf("Testing 'a': %c\n", ft_toupper('a'));
	printf("Testing ';': %c\n", ft_toupper(';'));
	printf("Testing 'A': %c\n", ft_toupper('A'));
	printf("Testing '0': %c\n", ft_toupper('0'));
	return (0);
}
*/
