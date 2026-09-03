/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:09:27 by hukhaw            #+#    #+#             */
/*   Updated: 2026/07/29 15:16:57 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
# include <ctype.h>
# include <stdio.h>

int	main(void)
{
	printf("System: ---\n");
	printf("Testing '1': %d\n", isalnum('1'));
	printf("Testing 'a': %d\n", isalnum('a'));
	printf("Testing 'P': %d\n", isalnum('P'));
	printf("Testing ',': %d\n", isalnum(','));
	printf("Testing ' ': %d\n", isalnum(' '));
	printf("ft: ---\n");
	printf("Testing '1': %d\n", ft_isalnum('1'));
	printf("Testing 'a': %d\n", ft_isalnum('a'));
	printf("Testing 'P': %d\n", ft_isalnum('P'));
	printf("Testing ',': %d\n", ft_isalnum(','));
	printf("Testing ' ': %d\n", ft_isalnum(' '));
	return (0);
}
*/
