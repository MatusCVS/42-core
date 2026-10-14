/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:08:46 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/09/26 14:12:51 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(const t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (!a->top || a->top->next == a->top)
		return (0.0);
	while (i->next != a->top)
	{
		j = i->next;
		while (j != a->top)
		{
			total_pairs += 1;
			if (i->value > j->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double) total_pairs);
}
