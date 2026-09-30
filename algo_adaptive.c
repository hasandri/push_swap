/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:17:57 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:32 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_ctx data)
{
	float	disorder;

	data.bench.strategy = "Adaptive";
	disorder = compute_disorder(&data.stack_a);
	if (disorder < 0.2)
	{
		data.bench.complexity = "O(n²)";
		simple(data);
	}
	else if (disorder < 0.5)
	{
		data.bench.complexity = "O(n√n)";
		medium(data);
	}
	else
	{
		data.bench.complexity = "O(n log n)";
		complex(data);
	}
}
