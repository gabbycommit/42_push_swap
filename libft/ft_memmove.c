/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_memmove.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hukhaw <hukhaw@student.42penang.edu.my>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/07/30 12:39:35 by hukhaw			   #+#	  #+#			  */
/*	 Updated: 2026/07/30 13:49:09 by hukhaw			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION:
		The memmove() function copies n bytes from memory area src to
		memory area dest.  The memory areas may overlap: copying takes
		place as though the bytes in src are first copied into a temporary
		array that does not overlap src or dest, and the bytes are then
		copied from the temporary array to dest.

	RETURN:
		The memmove() function returns a pointer to dest.

	SYNOPSIS:
		void	*memmove(size_t n;
					void dest[n], const void src[n], size_t n);
	
		The declaration is using VLA (Variable Length Array) Syntax. Starting
		C99, C allows parameter definitions where the size variable comes first
	
		which the size_t n;
		The parameter dest is an array that must have at least n bytes allocated.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_d;
	const unsigned char	*temp_s;
	size_t				i;

	if (n == 0 || dest == src)
		return (dest);
	temp_d = (unsigned char *)dest;
	temp_s = (const unsigned char *)src;
	if (temp_d > temp_s)
	{
		while (n--)
			temp_d[n] = temp_s[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	// System
	printf("System: --\n");
	char	*s1 = "hello, world";
	char	d1[13];
	printf("--- Testing no overlap: ---\n");
	printf("Original:\n");
	printf("Dest: %s\n", d1);
	printf("Src: %s\n", s1);
	memmove(d1, s1, 13);
	printf("Result: %s\n", d1);
	printf("--- Testing overlap: ---\n"); 
	char	s2[] = "hello, world";
	printf("Original: %s\n", s2);
	memmove(s2 + 2, s2, 10);
	printf("Result: %s\n", s2);

	// ft
	printf("\nft: --\n");
	char	*s3 = "hello, world";
	char	d2[13];
	printf("--- Testing no overlap: ---\n");
	printf("Original:\n");
	printf("Dest: %s\n", d2);
	printf("Src: %s\n", s3);
	ft_memmove(d2, s3, 13);
	printf("Result: %s\n", d2);
	printf("--- Testing overlap: ---\n"); 
	char	s4[] = "hello, world";
	printf("Original: %s\n", s4);
	ft_memmove(s4 + 2, s4, 10);
	printf("Result: %s\n", s4);
	return (0);
}
*/
