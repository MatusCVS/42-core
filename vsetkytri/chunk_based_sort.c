/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 22:44:01 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/10/15 17:04:34 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_width(int n)
{
	if (n <= 20)
		return (5);
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (35);
	return (n / 12 + 1);
}

static void	push_chunks(t_stack *a, t_stack *b, int width)
{
	int	sent;
	int	rank;

	sent = 0;
	while (a->size > 0)
	{
		rank = a->top->rank;
		if (rank <= sent)
		{
			pb(a, b, 1);
			if (b->size > 1)
				rb(b, 1);
			sent++;
		}
		else if (rank <= sent + width)
		{
			pb(a, b, 1);
			sent++;
		}
		else
			ra(a, 1);
	}
}

static int	max_position(t_stack *b)
{
	t_node	*node;
	int		i;
	int		pos;
	int		max;

	node = b->top;
	i = 0;
	pos = 0;
	max = -1;
	while (i < b->size)
	{
		if (node->rank > max)
		{
			max = node->rank;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

static void	pull_back(t_stack *a, t_stack *b)
{
	int	pos;
	int	steps;

	while (b->size > 0)
	{
		pos = max_position(b);
		if (pos <= b->size / 2)
		{
			while (pos-- > 0)
				rb(b, 1);
		}
		else
		{
			steps = b->size - pos;
			while (steps-- > 0)
				rrb(b, 1);
		}
		pa(b, a, 1);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		return ;
	assign_rank(a);
	push_chunks(a, b, chunk_width(a->size));
	pull_back(a, b);
}
