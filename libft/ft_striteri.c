/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:43:46 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 15:59:12 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
#include <ctype.h>

void	test_function(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = toupper((unsigned char)*c);
	else
		*c = tolower((unsigned char)*c);
}

int	main(void)
{
	char	s[] = "hello, 42";

	printf("Original str: %s\n", s);
	ft_striteri(s, test_function);
	printf("After: %s\n", s);
	return (0);
}
*/
