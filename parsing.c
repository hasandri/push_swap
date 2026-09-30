/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasandri <hasandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:21:17 by hasandri          #+#    #+#             */
/*   Updated: 2026/05/10 15:54:14 by hasandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_space(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	parse_numbers(char **argv, t_stack **stack_a, char **split)
{
	int		i;
	long	content;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen((const char *)argv[i]) > 11)
			ft_error(stack_a, split);
		if (!check_number(argv[i]))
			ft_error(stack_a, split);
		content = ft_atol(argv[i]);
		if (content > 2147483647 || content < -2147483648)
			ft_error(stack_a, split);
		if (check_duplicate(*stack_a, content))
			ft_error(stack_a, split);
		ft_lstadd_back(stack_a, ft_lstnew((int)content));
		i++;
	}
}

static	void	check_flag_and_pars(t_ctx *data, char **argv, int i)
{
	char	**nbr;

	if (ft_strcmp(argv[i], "--simple") == 0)
		data->bench.strat = SIMPLE;
	else if (ft_strcmp(argv[i], "--medium") == 0)
		data->bench.strat = MEDIUM;
	else if (ft_strcmp(argv[i], "--complex") == 0)
		data->bench.strat = COMPLEX;
	else if (ft_strcmp(argv[i], "--adaptive") == 0)
		data->bench.strat = ADAPTIVE;
	else if (ft_strcmp(argv[i], "--bench") == 0)
		data->bench.isbench = 1;
	else
	{
		nbr = ft_split(argv[i], ' ');
		if (!nbr)
			return ;
		parse_numbers(nbr, &data->stack_a, nbr);
		free_arg(nbr);
	}
}

void	parse_args(int argc, char **argv, t_ctx *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_space(argv[i]) == 1)
		{
			ft_printf(2, "Error\n");
			free_stack(&data->stack_a);
			exit(EXIT_FAILURE);
		}
		check_flag_and_pars(data, argv, i);
		i++;
	}
}
