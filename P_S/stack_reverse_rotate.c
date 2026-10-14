/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:27:01 by moaks             #+#    #+#             */
/*   Updated: 2026/09/25 21:40:26 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int print)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->previous;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int print)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->previous;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
