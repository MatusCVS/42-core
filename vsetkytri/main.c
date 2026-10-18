/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/10/18 16:30:05 by mmiklovi         ###   ########.fr       */
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
	if (a->size == 3)
		sort_three(a);
	else if (disorder < 0.2)
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
	else if (mode == SIMPLE)
		selection_sort(a, b);
	else if (mode == MEDIUM)
		chunk_sort(a, b);
	else if (mode == COMPLEX)
		radix_sort(a, b);
}

static int	error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		flags;

	ft_bzero(&data, sizeof(data));
	data.a.bench = &data.stats;
	data.b.bench = &data.stats;
	flags = parse_flags(argv, &data);
	if (argc < 2)
		return (0);
	if (flags == -1)
		return (error(&data.a));
	if (!fill_stack_a(&data.a, argv, argc, flags))
		return (error(&data.a));
	if (!is_sorted(&data.a))
	{
		data.disorder = compute_disorder(&data.a);
		dispatcher(&data.a, &data.b, data.mode, data.disorder);
	}
	if (data.bench == TRUE)
		print_bench(&data);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
