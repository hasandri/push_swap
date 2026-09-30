/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:21:10 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/08 06:49:44 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_stack *stack_a, int content)
{
	while (stack_a)
	{
		if (stack_a->content == content)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

long	ft_atol(char *argv)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sign *= -1;
		i++;
	}
	while (argv[i])
	{
		result = (result * 10) + (argv[i] - '0');
		i++;
	}
	return (result * sign);
}
