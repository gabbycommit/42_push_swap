/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:43:58 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 14:55:35 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("System:---\n");
	printf("Testing 'c': %d\n", isalpha('c'));
	printf("Testing 'A': %d\n", isalpha('A'));
	printf("Testing '&': %d\n", isalpha('&'));
	printf("Testing '1': %d\n", isalpha('1'));
	printf("Testing ' ': %d\n", isalpha(' '));
	printf("ft:---\n");
	printf("Testing 'c': %d\n", ft_isalpha('c'));
	printf("Testing 'A': %d\n", ft_isalpha('A'));
	printf("Testing '&': %d\n", ft_isalpha('&'));
	printf("Testing '1': %d\n", ft_isalpha('1'));
	printf("Testing ' ': %d\n", ft_isalpha(' '));
	return (0);
}
*/
