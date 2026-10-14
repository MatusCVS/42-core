/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/10/14 23:01:37 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	t_node	*current;
	int		i;

	if (a->size < 2)
		return (1);
	current = a->top;
	i = 1;
	while (i < a->size)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

static void	adaptive_sort(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		selection_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}

static void	dispatcher(t_stack *a, t_stack *b, int mode, double disorder)
{
	if (mode == NO_FLAG || mode == ADAPTIVE)
		adaptive_sort(a, b, disorder);
	else if (mode == BENCH)
		chunk_sort(a, b);
	else if (mode == SIMPLE)
		selection_sort(a, b);
	else if (mode == MEDIUM)
		chunk_sort(a, b);
	else if (mode == COMPLEX)
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		mode;
	double	disorder;

	if (argc < 2)
		return (0);
	mode = get_mode(argv[1]);
	a = new_stack(0, NULL);
	b = new_stack(0, NULL);
	if (!fill_stack_a(&a, argv, argc, mode))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	if (!is_sorted(&a))
	{
		disorder = compute_disorder(&a);
		dispatcher(&a, &b, mode, disorder);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
