/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:42 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:46 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_ctx *data)
{
	int	min_idx;
	int	size;

	size = ft_lstsize(data->stack_a);
	while (size > 3)
	{
		min_idx = to_find_min_index(&data->stack_a);
		size = ft_lstsize(data->stack_a);
		if (min_idx == 0)
		{
			pb(data);
			size--;
		}
		else if (min_idx <= size / 2)
			ra(&data->stack_a, &data->bench);
		else
			rra(&data->stack_a, &data->bench);
	}
}

void	simple(t_ctx data)
{
	float	disorder;
	int		size;

	disorder = compute_disorder(&data.stack_a);
	size = ft_lstsize(data.stack_a);
	if (size == 2)
		sort_two(&data.stack_a, &data.bench);
	else if (size == 3)
		sort_three(&data.stack_a, &data.bench);
	else
		selection_sort(&data);
	if (data.bench.isbench == 1)
		check_benchmark_strat(&data, disorder);
	free_stack(&data.stack_a);
}
