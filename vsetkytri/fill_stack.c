/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/10/15 18:41:13 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_number(const char *nptr, int i, int sign, int *value)
{
	long	result;

	result = 0;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	*value = (int)(result * sign);
	return (1);
}

static int	safe_atoi(const char *nptr, int *value)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_number(nptr, i, sign, value));
}

int	fill_stack_a(t_stack *a, char **argv, int argc, int index)
{
	t_node	*node;
	int		value;
	int		i;

	i = index;
	while (i < argc)
	{
		if (!safe_atoi(argv[i], &value))
			return (0);
		if (has_duplicate(a, value))
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
		node->previous = node;
		stack->top = node;
	}
	else
	{
		node->next = stack->top;
		node->previous = stack->top->previous;
		stack->top->previous->next = node;
		stack->top->previous = node;
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
	while (stack->size > 0)
	{
		next = current->next;
		free(current);
		current = next;
		stack->size--;
	}
	stack->top = NULL;
}
