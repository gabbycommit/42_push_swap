/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:25:37 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 15:38:31 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("System: ---\n");
	printf("Testing: ' ': %d\n", isascii(' '));
	printf("Testing: 'a': %d\n", isascii('a'));
	printf("Testing: '4': %d\n", isascii('4'));
	printf("Testing: 'H': %d\n", isascii('H'));
	printf("Testing: '!': %d\n", isascii('!'));
	printf("Testing: '?': %d\n", isascii('?'));
	printf("Testing: '\\0': %d\n", isascii('\0'));
	printf("Testing: '\\n': %d\n", isascii('\n'));
	printf("Testing: ascii 130: %d\n", isascii(130));
	printf("ft: ---\n");
	printf("Testing: ' ': %d\n", ft_isascii(' '));
	printf("Testing: 'a': %d\n", ft_isascii('a'));
	printf("Testing: '4': %d\n", ft_isascii('4'));
	printf("Testing: 'H': %d\n", ft_isascii('H'));
	printf("Testing: '!': %d\n", ft_isascii('!'));
	printf("Testing: '?': %d\n", ft_isascii('?'));
	printf("Testing: '\\0': %d\n", ft_isascii('\0'));
	printf("Testing: '\\n': %d\n", ft_isascii('\n'));
	printf("Testing: ascii 130: %d\n", ft_isascii(130));
	return (0);
}
*/
