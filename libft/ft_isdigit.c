/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:56:35 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 15:04:36 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("System: ---\n");
	printf("Testing '9': %d\n", isdigit('9'));
	printf("Testing 'a': %d\n", isdigit('a'));
	printf("Testing '0': %d\n", isdigit('0'));
	printf("Testing ',': %d\n", isdigit(','));
	printf("Testing ' ': %d\n", isdigit(' '));
	printf("ft: ---\n");
	printf("Testing: '9': %d\n", ft_isdigit('9'));
	printf("Testing: 'a': %d\n", ft_isdigit('a'));
	printf("Testing: '0': %d\n", ft_isdigit('0'));
	printf("Testing: ',': %d\n", ft_isdigit(','));
	printf("Testing: ' ': %d\n", ft_isdigit(' '));
	return (0);
}
*/
