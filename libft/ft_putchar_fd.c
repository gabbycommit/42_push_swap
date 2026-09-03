/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:59:48 by hukhaw            #+#    #+#             */
/*   Updated: 2026/08/03 16:28:07 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	DESCRIPTION:
 * 		Outputs the character ’c’ to the specified file
 *		descriptor.
 */

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
int	main(void)
{
	ft_putchar_fd('P', 1);
}
*/
