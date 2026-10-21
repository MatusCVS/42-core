/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:51:34 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/10/18 16:28:05 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		i;

	current = a->top;
	min = current->value;
	min_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *a, int min_pos)
{
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < a->size)
		{
			rra(a, 1);
			min_pos++;
		}
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 0)
	{
		min_pos = find_min_position(a);
		move_min_to_top(a, min_pos);
		pb(a, b, 1);
	}
	while (b->size > 0)
		pa(b, a, 1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
	}
	void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = find_min_position(a);
		move_min_to_top(a, min_pos);
		pb(a, b, 1);
	}
	sort_three(a);
	while (b->size > 0)
		pa(b, a, 1);
}