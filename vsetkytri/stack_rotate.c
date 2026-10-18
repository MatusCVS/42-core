/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:26:41 by moaks             #+#    #+#             */
/*   Updated: 2026/10/15 18:32:07 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	if (print)
	{
		ft_printf("ra\n");
		count_op(a, RA);
	}
}

void	rb(t_stack *b, int print)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	if (print)
	{
		ft_printf("rb\n");
		count_op(b, RB);
	}
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
	{
		ft_printf("rr\n");
		count_op(a, RR);
	}
}
