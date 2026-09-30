/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:21:03 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/07 17:49:33 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack **node)
{
	t_stack	*tmp;

	tmp = *node;
	*node = tmp->next;
	tmp->next = (*node)->next;
	(*node)->next = tmp;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	bench->ops_sa++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "sa");
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	bench->ops_sb++;
	bench->tot_ops++;
	ft_printf(1, "%s\n", "sb");
}

void	ss(t_ctx *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	data->bench.ops_ss++;
	data->bench.tot_ops++;
	ft_printf(1, "%s\n", "ss");
}
