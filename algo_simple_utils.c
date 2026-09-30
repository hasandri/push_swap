/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:42 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:42 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	val(t_stack *stack, int i)
{
	while (i-- > 0)
		stack = stack->next;
	return (stack->content);
}

void	sort_two(t_stack **a, t_bench *bench)
{
	if (val(*a, 0) > val(*a, 1))
		sa(a, bench);
}

static void	sort_three_case(t_stack **a, t_bench *bench, int v0, int v1)
{
	int	v2;

	v2 = val(*a, 2);
	if (v0 > v1 && v1 > v2)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (v0 < v1 && v1 > v2 && v0 < v2)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (v0 > v1 && v1 < v2 && v0 > v2)
		ra(a, bench);
	else if (v0 < v1 && v1 > v2 && v0 > v2)
		rra(a, bench);
	else
		sa(a, bench);
}

void	sort_three(t_stack **a, t_bench *bench)
{
	int	v0;
	int	v1;

	v0 = val(*a, 0);
	v1 = val(*a, 1);
	if (v0 < v1 && v1 < val(*a, 2))
		return ;
	sort_three_case(a, bench, v0, v1);
}

void	selection_sort(t_ctx *data)
{
	push_min_to_b(data);
	sort_three(&data->stack_a, &data->bench);
	while (data->stack_b)
		pa(data);
}
