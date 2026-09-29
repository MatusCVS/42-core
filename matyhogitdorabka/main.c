/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/09/29 20:18:02 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatcher(t_stack *a, t_stack *b, int mode, double disorder)
{
	if (mode == NO_FLAG)
	{
		if (disorder < 0.2)
			selection_sort(a, b);
		else if (disorder < 0.5)
		{
			// medium sort
		}
		else
		{
			// complex sort
		}
	}
	else if (mode == BENCH)
	{
		// bude doplnene
	}
	else if (mode == SIMPLE)
		selection_sort(a, b);
	else if (mode == MEDIUM)
	{
		// medium
	}
	else if (mode == COMPLEX)
	{
		// complex
	}
	else if (mode == ADAPTIVE)
	{
		// adaptive
	}
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
		return (1);
	}
	disorder = compute_disorder(&a);
	dispatcher(&a, &b, mode, disorder);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
