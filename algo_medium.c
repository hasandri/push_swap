/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:33 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:39 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (0);
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_to_stack_a(t_ctx *data)
{
	int	size_b;
	int	max_pos;

	while (data->stack_b)
	{
		size_b = ft_lstsize(data->stack_b);
		max_pos = to_find_max_index(&data->stack_b);
		if (max_pos == 0)
			pa(data);
		else if (max_pos <= size_b / 2)
			rb(&data->stack_b, &data->bench);
		else
			rrb(&data->stack_b, &data->bench);
	}
}

static void	medium_algo(t_ctx *data)
{
	int	size;
	int	chunk;
	int	i;

	size = ft_lstsize(data->stack_a);
	if (size <= 1)
		return ;
	chunk = size / ft_sqrt(size);
	i = 0;
	while (data->stack_a)
	{
		if (data->stack_a->content <= chunk + i)
		{
			pb(data);
			i++;
		}
		else
			ra(&data->stack_a, &data->bench);
	}
	push_to_stack_a(data);
}

void	medium(t_ctx data)
{
	float	disorder;

	disorder = compute_disorder(&data.stack_a);
	assign_ranks(&data.stack_a);
	medium_algo(&data);
	if (data.bench.isbench == 1)
		check_benchmark_strat(&data, disorder);
	free_stack(&data.stack_a);
}
