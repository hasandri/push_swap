/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:20:42 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/07 17:49:24 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_ctx *data)
{
	push(&data->stack_b, &data->stack_a);
	data->bench.ops_pa++;
	data->bench.tot_ops++;
	ft_printf(1, "%s\n", "pa");
}

void	pb(t_ctx *data)
{
	push(&data->stack_a, &data->stack_b);
	data->bench.ops_pb++;
	data->bench.tot_ops++;
	ft_printf(1, "%s\n", "pb");
}
