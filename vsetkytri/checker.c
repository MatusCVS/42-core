/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 22:26:49 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/10/15 18:51:33 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_stack(t_stack *a)
{
	t_node	*node;
	t_node	*other;
	int		i;
	int		j;

	node = a->top;
	i = 0;
	while (i++ < a->size)
	{
		other = node->next;
		j = i;
		while (j++ < a->size)
		{
			if (other->value == node->value)
				return (0);
			other = other->next;
		}
		node = node->next;
	}
	return (1);
}

static int	run_operation(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(b, a, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(a, b, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static int	read_operations(t_stack *a, t_stack *b)
{
	char	*line;
	int		ok;

	line = get_next_line(0);
	while (line)
	{
		ok = run_operation(line, a, b);
		free(line);
		if (!ok)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

static int	is_sorted(t_stack *a)
{
	t_node	*node;
	int		i;

	node = a->top;
	i = 1;
	while (i < a->size)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ok;

	if (argc < 2)
		return (0);
	a = new_stack(0, NULL);
	b = new_stack(0, NULL);
	ok = fill_stack_a(&a, argv, argc, 1);
	if (ok)
		ok = valid_stack(&a);
	if (ok)
		ok = read_operations(&a, &b);
	if (!ok)
		write(2, "Error\n", 6);
	else if (b.size == 0 && is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (!ok);
}
