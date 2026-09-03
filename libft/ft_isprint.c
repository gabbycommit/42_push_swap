/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:44:51 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 16:02:22 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("System: ---\n");
	printf("Testing 'a': %d\n", isprint('a'));
	printf("Testing '1': %d\n", isprint('1'));
	printf("Testing 'P': %d\n", isprint('P'));
	printf("Testing ':': %d\n", isprint(':'));
	printf("Testing '\\n': %d\n", isprint('\n'));
	printf("Testing '\\r': %d\n", isprint('\r'));
	printf("Testing ascii 127(delete): %d\n", isprint(127));
	printf("Testing ' ': %d\n", isprint(' '));
	printf("f: ---\n");
	printf("Testing 'a': %d\n", ft_isprint('a'));
	printf("Testing '1': %d\n", ft_isprint('1'));
	printf("Testing 'P': %d\n", ft_isprint('P'));
	printf("Testing ':': %d\n", ft_isprint(':'));
	printf("Testing '\\n': %d\n", ft_isprint('\n'));
	printf("Testing '\\r': %d\n", ft_isprint('\r'));
	printf("Testing ascii 127(delete): %d\n", ft_isprint(127));
	printf("Testing ' ': %d\n", ft_isprint(' '));
	return (0);
}
*/
