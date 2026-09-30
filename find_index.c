/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:19:04 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:53 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_find_min_index(t_stack **stack_a)
{
	int		min;
	int		index;
	int		i;
	t_stack	*tmp;

	tmp = *stack_a;
	min = tmp->content;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	to_find_max_index(t_stack **stack_a)
{
	int		max;
	int		index;
	int		i;
	t_stack	*tmp;

	tmp = *stack_a;
	max = tmp->content;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	assign_ranks(t_stack **stack_a)
{
	int		*index;
	int		i;
	t_stack	*tmp;

	index = get_sorted_values(stack_a);
	if (!index)
		return ;
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (index[i] != tmp->content)
			i++;
		tmp->content = i;
		tmp = tmp->next;
	}
	free(index);
}
