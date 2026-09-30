/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:06 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:48 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	benchmark(t_ctx data, float disorder)
{
	char	*strategy;
	char	*complexity;

	strategy = data.bench.strategy;
	complexity = data.bench.complexity;
	if (!strategy)
		strategy = "None";
	if (!complexity)
		complexity = "None";
	ft_printf(2, "[bench] disorder: %f%%\n", disorder * 100);
	ft_printf(2, "[bench] strategy: %s / %s\n", strategy, complexity);
	ft_printf(2, "[bench] total_ops: %d\n", data.bench.tot_ops);
	ft_printf(2, "[bench] sa: %d\tsb: %d\tss: %d\tpa: %d\tpb: %d\n",
		data.bench.ops_sa, data.bench.ops_sb, data.bench.ops_ss,
		data.bench.ops_pa, data.bench.ops_pb);
	ft_printf(2, "[bench] ra: %d\trb: %d\trr: %d\trra: %d\trrb: %d\trrr: %d\n",
		data.bench.ops_ra, data.bench.ops_rb, data.bench.ops_rr,
		data.bench.ops_rra, data.bench.ops_rrb, data.bench.ops_rrr);
}

void	check_benchmark_strat(t_ctx *data, float disorder)
{
	if (data->bench.strat == SIMPLE)
	{
		data->bench.complexity = "O(n²)";
		data->bench.strategy = "Simple";
	}
	else if (data->bench.strat == MEDIUM)
	{
		data->bench.complexity = "O(n√n)";
		data->bench.strategy = "Medium";
	}
	else if (data->bench.strat == COMPLEX)
	{
		data->bench.complexity = "O(n log n)";
		data->bench.strategy = "Complex";
	}
	benchmark(*data, disorder);
}
