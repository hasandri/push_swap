/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:20:49 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/11 16:35:06 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	bench->ops_rra++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "rra");
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	bench->ops_rrb++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "rrb");
}

void	rrr(t_ctx *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	data->bench.ops_rrr++;
	data->bench.tot_ops++;
	ft_printf(1, "%s\n", "rrr");
}
