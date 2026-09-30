/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:19:57 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/07 19:29:22 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_ctx *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->bench.strat = 0;
	data->bench.isbench = 0;
	data->bench.ops_pa = 0;
	data->bench.ops_pb = 0;
	data->bench.ops_sa = 0;
	data->bench.ops_sb = 0;
	data->bench.ops_ss = 0;
	data->bench.ops_ra = 0;
	data->bench.ops_rb = 0;
	data->bench.ops_rr = 0;
	data->bench.ops_rra = 0;
	data->bench.ops_rrb = 0;
	data->bench.ops_rrr = 0;
	data->bench.tot_ops = 0;
	data->bench.strategy = NULL;
	data->bench.complexity = NULL;
}

static	void	set_adaptive_small(t_ctx *data, float disorder)
{
	data->bench.strategy = "Adaptive";
	if (disorder < 0.2)
		data->bench.complexity = "O(n²)";
	else if (disorder < 0.5)
		data->bench.complexity = "O(n√n)";
	else
		data->bench.complexity = "O(n log n)";
}

static	void	check_strat(t_ctx data, float disorder)
{
	int	size;

	size = ft_lstsize(data.stack_a);
	if (size <= 5)
	{
		if (data.bench.strat == ADAPTIVE)
			set_adaptive_small(&data, disorder);
		simple(data);
		return ;
	}
	if (data.bench.strat == SIMPLE)
		simple(data);
	else if (data.bench.strat == MEDIUM)
		medium(data);
	else if (data.bench.strat == COMPLEX)
		complex(data);
	else
		adaptive(data);
}

int	main(int argc, char **argv)
{
	float	disorder;
	t_ctx	data;

	init_data(&data);
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &data);
	disorder = compute_disorder(&data.stack_a);
	if (disorder == 0)
	{
		if (data.bench.isbench == 1)
			benchmark(data, disorder);
		free_stack(&data.stack_a);
		exit(EXIT_SUCCESS);
	}
	check_strat(data, disorder);
	return (0);
}
