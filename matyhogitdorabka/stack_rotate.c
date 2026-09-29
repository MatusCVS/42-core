/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:26:41 by moaks             #+#    #+#             */
/*   Updated: 2026/09/26 13:42:12 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	if (!a->top || a->top->next == a->top)
		return ;
	a->top = a->top->next;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int print)
{
	if (!b->top || b->top->next == b->top)
		return ;
	b->top = b->top->next;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *n, int print)
{
	ra(a, 0);
	rb(a, 0);
	if (print)
		ft_printf("rr\n");
}
