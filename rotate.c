/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:20:56 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/11 16:35:56 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	bench->ops_ra++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "ra");
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	bench->ops_rb++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "rb");
}

void	rr(t_ctx *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	data->bench.ops_rr++;
	data->bench.tot_ops++;
	ft_printf(1, "%s\n", "rr");
}
