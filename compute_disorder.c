/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:25 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:51 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack **stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	i = *stack_a;
	mistakes = 0;
	total_pairs = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->content > j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.00);
	return ((float)mistakes / total_pairs);
}
