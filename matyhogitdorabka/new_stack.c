/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/09/26 19:27:02 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	new_stack(int size, t_node *top)
{
	t_stack	stack;

	stack.size = size;
	stack.top = top;
	return (stack);
}

static int	safe_atoi(const char *nptr, int *value)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	*value = (int)(result * sign);
	return (1);
}

int	fill_stack_a(t_stack *a, char **argv, int argc, int mode)
{
	t_node	*node;
	int		value;
	int		i;

    if (mode == NO_FLAG)
	    i = 1;
    else
        i = 2;
	while (i < argc)
	{
		if (!safe_atoi(argv[i], &value))
			return (0);
		node = new_node(value);
		if (!node)
			return (0);
		attach_node_at_bottom(a, node);
		i++;
	}
	return (1);
}

void	attach_node_at_bottom(t_stack *stack, t_node *node)
{
	if (!stack->top)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack->top)
		return ;
	current = stack->top;
	do {
		next = current->next;
		free(current);
		current = next;
	} while (current != stack->top);
	stack->top = NULL;
	stack->size = 0;
}
