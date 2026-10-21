/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:54:44 by moaks             #+#    #+#             */
/*   Updated: 2026/10/18 16:28:38 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

/*circular doubly linked list, stack*/
typedef struct t_node
{
	int				value;
	int				rank;
	struct t_node	*next;
	struct t_node	*previous;
}	t_node;

typedef enum s_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_bench
{
	int	count[OP_COUNT];
}	t_bench;

typedef struct t_stack
{
	int		size;
	t_node	*top;
	t_bench	*bench;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_bench	stats;
	int		mode;
	int		bench;
	double	disorder;
}	t_data;

typedef enum s_mode
{
	NO_FLAG = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

typedef enum s_bool
{
	FALSE = 0,
	TRUE
}	t_bool;

/* New node and new stack */
t_node	*new_node(int value);
t_stack	new_stack(int size, t_node *top);
int		has_duplicate(t_stack *stack, int value);
int		fill_stack_a(t_stack *a, char **argv, int argc, int mode);
void	attach_node_at_bottom(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
int		get_mode(char *argv1);
int		get_bench(char *argv1);
void	count_op(t_stack *s, t_op op);
int		parse_flags(char **argv, t_data *data);

/* Operations */
void	sa(t_stack *a, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	sb(t_stack *b, int print);
void	pa(t_stack *b, t_stack *a, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);

/* Disorder metric */
double	compute_disorder(const t_stack *a);

/* Sorting algorithms */
void	radix_sort(t_stack *a, t_stack *b);
void	selection_sort(t_stack *a, t_stack *b);
void	chunk_sort(t_stack *a, t_stack *b);
void	assign_rank(t_stack *a);

/*bench mode*/
int		ft_printf_strerr(const char *format, ...);
void	print_bench(t_data *data);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

#endif
