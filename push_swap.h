/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fetraand <fetraand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:21:24 by fetraand          #+#    #+#             */
/*   Updated: 2026/05/12 20:50:42 by fetraand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef enum e_stratege
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}	t_stratege;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int			isbench;
	int			ops_sa;
	int			ops_sb;
	int			ops_ss;
	int			ops_pa;
	int			ops_pb;
	int			ops_ra;
	int			ops_rb;
	int			ops_rr;
	int			ops_rra;
	int			ops_rrb;
	int			ops_rrr;
	int			tot_ops;
	char		*strategy;
	char		*complexity;
	t_stratege	strat;
}	t_bench;

typedef struct s_ctx
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bench	bench;
}	t_ctx;

void	adaptive(t_ctx data);
void	simple(t_ctx data);
void	medium(t_ctx data);
void	complex(t_ctx data);
void	assign_ranks(t_stack **stack_a);
void	sort_two(t_stack **a, t_bench *bench);
void	sort_three(t_stack **a, t_bench *bench);
void	selection_sort(t_ctx *data);
void	push_min_to_b(t_ctx *data);
void	benchmark(t_ctx data, float disorder);
float	compute_disorder(t_stack **stack_a);

void	check_benchmark_strat(t_ctx *data, float disorder);

void	pa(t_ctx *data);
void	pb(t_ctx *data);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_ctx *data);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_ctx *data);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_ctx *data);

int		ft_lstsize(t_stack *stack);
t_stack	*ft_lstlast(t_stack *stack);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

void	ft_error(t_stack **a, char **split);
void	free_stack(t_stack **stack);
void	free_arg(char **split);

size_t	ft_strlen(const char *s);
int		check_number(char *argv);
int		check_duplicate(t_stack *stack_a, int content);
long	ft_atol(char *argv);

void	parse_args(int argc, char **argv, t_ctx *data);

char	**ft_split(char const *s, char c);

int		to_find_min_index(t_stack **stack_a);
int		to_find_max_index(t_stack **stack_a);

int		*get_sorted_values(t_stack **stack_a);

#endif