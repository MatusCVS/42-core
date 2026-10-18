/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:10:19 by moaks             #+#    #+#             */
/*   Updated: 2026/10/15 17:17:41 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack	new_stack(int size, t_node *top)
{
	t_stack	stack;

	stack.size = size;
	stack.top = top;
	stack.bench = NULL;
	return (stack);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;
	int		i;

	if (!stack->top)
		return (0);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}
