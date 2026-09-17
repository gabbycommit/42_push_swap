/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_complex_quick_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hukhaw <hukhaw@student.42penang.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:50:30 by hukhaw            #+#    #+#             */
/*   Updated: 2026/09/17 12:00:22 by hukhaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ps_sort_a(t_stack **a, t_stack **b, t_config *config, int size);
static void	ps_sort_b(t_stack **a, t_stack **b, t_config *config, int size);

static void	print_single(t_stack *stack, const char *name)
{
	printf("Stack %s (Top->Bottom): [ ", name);
	while (stack)
	{
		printf("%d", stack->rank);
		if (stack->next)
			printf(" -> ");
		stack = stack->next;
	}
	printf("%s ]\n", stack ? "" : "EMPTY");
}

static void	debug_print(t_stack *a, t_stack *b, const char *op)
{
	printf("\n\033[1;32m===> Operation: %-5s\033[0m\n", op);
	print_single(a, "A");
	print_single(b, "B");
	printf("----------------------------------------\n");
}

static int	ps_get_pivot(t_stack *stack, int size)
{
	int	min;
	int	max;
	int	i;

	min = stack->rank;
	max = stack->rank;
	i = 0;
	while (i < size)
	{
		if (stack->rank < min)
			min = stack->rank;
		/* 【修改點 1】：改為獨立 if，避免 else 強制覆蓋 max */
		if (stack->rank > max)
			max = stack->rank;
		stack = stack->next;
		i++;
	}
	return ((min + max) / 2);
}

/* 【修改點 2】：修正 swap 邏輯，並只在真正發生 Swap 時調用 debug_print */
static void	ps_sort_small(t_stack **a, t_stack **b, t_config *config, int is_a)
{
	if (is_a && (*a)->rank > (*a)->next->rank)
	{
		ps_swap_a(a, config, 1);
		debug_print(*a, *b, "sa");
	}
	else if (!is_a && (*b)->rank < (*b)->next->rank)
	{
		ps_swap_b(b, config, 1);
		debug_print(*a, *b, "sb");
	}
}

static void	ps_restore(t_stack **a, t_stack **b, t_config *config, int times, int is_a)
{
	int	i;

	/* 【修改點 3】：根據 is_a 分別檢查 *a 或 *b 的總長度，避免用 *a 誤判 B */
	if (is_a && (size_t)times == ps_lstcount(*a))
		return ;
	if (!is_a && (size_t)times == ps_lstcount(*b))
		return ;
	i = 0;
	while (i < times)
	{
		if (is_a)
		{
			ps_reverse_rotate_a(a, config, 1);
			debug_print(*a, *b, "rra");
		}
		else
		{
			ps_reverse_rotate_b(b, config, 1);
			debug_print(*a, *b, "rrb");
		}
		i++;
	}
}

static void	ps_sort_b(t_stack **a, t_stack **b, t_config *config, int size)
{
	int	push;
	int	rotate;
	int	i;
	int	pivot;

	if (size == 0)
		return ;
	/* 【修改點 4】：補上 return 與 debug_print，防止清空 B 後存取 NULL 引發 Segfault */
	if (size == 1)
	{
		ps_push_a(a, b, config);
		debug_print(*a, *b, "pa");
		return ;
	}
	/* 【修改點 5】：新增 size == 2 邊界情況處理，提升效率 */
	if (size == 2)
	{
		ps_sort_small(a, b, config, 0);
		ps_push_a(a, b, config);
		debug_print(*a, *b, "pa");
		ps_push_a(a, b, config);
		debug_print(*a, *b, "pa");
		return ;
	}
	pivot = ps_get_pivot(*b, size);
	push = 0;
	rotate = 0;
	i = 0;
	while (i < size)
	{
		/* 【修改點 6】：將條件改為 >= pivot，將較大元素推回 A */
		if ((*b)->rank >= pivot)
		{
			ps_push_a(a, b, config);
			push++;
			debug_print(*a, *b, "pa");
		}
		else
		{
			ps_rotate_b(b, config, 1);
			rotate++;
			debug_print(*a, *b, "rb");
		}
		i++;
	}
	ps_sort_a(a, b, config, push);
	ps_restore(a, b, config, rotate, 0);
	ps_sort_b(a, b, config, size - push);
}

static void	ps_sort_a(t_stack **a, t_stack **b, t_config *config, int size)
{
	int	pivot;
	int	i;
	int	rotate;
	int	push;

	if (size == 1)
		return ;
	if (size == 2)
	{
		/* 【修改點 7】：移除無條件的 debug_print("sa")，改由 ps_sort_small 內部印出 */
		ps_sort_small(a, b, config, 1);
		return ;
	}
	pivot = ps_get_pivot(*a, size);
	rotate = 0;
	push = 0;
	i = 0;
	while (i < size)
	{
		if ((*a)->rank < pivot)
		{
			ps_push_b(a, b, config);
			push++;
			debug_print(*a, *b, "pb");
		}
		else
		{
			ps_rotate_a(a, config, 1);
			rotate++;
			debug_print(*a, *b, "ra");
		}
		i++; /* 【修改點 8】：補上 i++，修復原本致命的無窮迴圈 */
	}
	ps_restore(a, b, config, rotate, 1);
	ps_sort_a(a, b, config, size - push);
	ps_sort_b(a, b, config, push);
}

void	ps_complex_quick_sort(t_stack **a, t_stack **b, t_config *config)
{
	ps_init_rank(*a);
	printf("\033[1;33m=== 初始 Stack A 狀態 ===\033[0m\n");
	print_single(*a, "A");
	print_single(*b, "B");
	printf("----------------------------------------\n");

	ps_sort_a(a, b, config, ps_lstcount(*a));

	printf("\n\033[1;35m=== 最終 排序完成 狀態 ===\033[0m\n");
	print_single(*a, "A");
	print_single(*b, "B");
}
