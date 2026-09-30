/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:18:14 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/13 00:25:35 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	insertion_sort(int *sorted_vals, int size)
{
	int	i;
	int	j;
	int	key;

	if (!sorted_vals)
		return ;
	i = 1;
	while (i < size)
	{
		j = i - 1;
		key = sorted_vals[i];
		while (j >= 0 && sorted_vals[j] > key)
		{
			sorted_vals[j + 1] = sorted_vals[j];
			j--;
		}
		sorted_vals[j + 1] = key;
		i++;
	}
}

int	*get_sorted_values(t_stack **stack_a)
{
	int		*sorted_vals;
	int		size;
	int		i;
	t_stack	*tmp;

	size = ft_lstsize(*stack_a);
	sorted_vals = (int *)malloc(sizeof(int) * size);
	if (!sorted_vals)
		return (NULL);
	i = 0;
	tmp = *stack_a;
	while (i < size && tmp)
	{
		sorted_vals[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	insertion_sort(sorted_vals, size);
	return (sorted_vals);
}

static void	radix_algo(t_ctx *data, int bit)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(data->stack_a);
	while (i < size)
	{
		if (((((data->stack_a->content) >> bit)) & 1) == 0)
			pb(data);
		else
			ra(&data->stack_a, &data->bench);
		i++;
	}
	while (data->stack_b)
		pa(data);
}

void	complex(t_ctx data)
{
	int		size;
	int		bits_max;
	int		bit;
	float	disorder;

	disorder = compute_disorder(&data.stack_a);
	size = ft_lstsize(data.stack_a);
	assign_ranks(&data.stack_a);
	bits_max = 0;
	while (((size - 1) >> bits_max) != 0)
		bits_max++;
	bit = 0;
	while (bit < bits_max)
	{
		radix_algo(&data, bit);
		bit++;
	}
	if (data.bench.isbench == 1)
		check_benchmark_strat(&data, disorder);
	free_stack(&data.stack_a);
}
