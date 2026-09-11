/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ranking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:11:12 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/11 11:30:24 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ps_quick_sort(int *arr, int low, int high)
{
	int	pivot;
	int	pivot_idx;
	int	j;
	int	i;

	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] < pivot)
			{
				i++;
				ps_swap(&arr[i], &arr[j]);
			}
			j++;
		}
		ps_swap(&arr[i + 1], &arr[j]);
		pivot_idx = i + 1;
		ps_quick_sort(arr, low, pivot_idx - 1);
		ps_quick_sort(arr, pivot_idx + 1, high);
	}
}

static int	ps_binary_search(int *arr, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	ps_init_rank(t_stack *a)
{
	int		*arr;
	int		i;
	size_t	size;
	t_stack	*cur;

	size = ps_lstcount(a);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	cur = a;
	while (cur)
	{
		arr[i++] = cur->num;
		cur = cur->next;
	}
	ps_quick_sort(arr, 0, size - 1);
	cur = a;
	while (cur)
	{
		cur->rank = ps_binary_search(arr, size, cur->num) + 1;
		cur = cur->next;
	}
}
