/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 20:26:06 by moaks             #+#    #+#             */
/*   Updated: 2026/09/26 13:46:29 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	t_node	*tmp;

	if (!a->top || a->top->next == a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int print)
{
	t_node	*tmp;

	if (!b->top || b->top->next == b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_printf("ss\n");
}
