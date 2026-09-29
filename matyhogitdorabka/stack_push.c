/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 21:16:15 by moaks             #+#    #+#             */
/*   Updated: 2026/09/26 12:49:32 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	unlink_node(t_stack *src, t_stack *dst)
{
	t_node	*move;

	move = src->top;
	if (src->top->next == src->top)
		src->top = NULL;
	else
	{
		src->top = src->top->next;
		move->previous->next = move->next;
		move->next->previous = move->previous;
	}
	src->size--;
}

static void	attach_node(t_stack *dst, t_node *move)
{
	if (!dst->top)
	{
		move->next = move;
		move->previous = move;
	}
	else
	{
		move->next = dst->top;
		move->previous = dst->top->previous;
		dst->top->previous->next = move;
		dst->top->previous = move;
	}
	dst->top = move;
	dst->size++;
}

static void	move_node(t_stack *src, t_stack *dst)
{
	t_node	*move;

	move = src->top;
	unlink_node(src, move);
	attach_node(dst, move);
}

void	pa(t_stack *b, t_stack *a, int print)
{
	if (!b->top)
		return ;
	move_node(b, a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b, int print)
{
	if (!a->top)
		return ;
	move_node(a, b);
	if (print)
		ft_printf("pb\n");
}
