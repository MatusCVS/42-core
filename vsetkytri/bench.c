/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 22:26:49 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/10/18 13:30:36 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_mode(int mode, double disorder)
{
	if (mode == ADAPTIVE || mode == NO_FLAG)
	{
		ft_printf_strerr("Adaptive | ");
		if (disorder < 0.2)
			ft_printf_strerr("O(n2)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_printf_strerr("O(n√n)\n");
		else if (disorder >= 0.5)
			ft_printf_strerr("O(n log n)\n");
	}
	else if (mode == SIMPLE)
		ft_printf_strerr("Simple | O(n2)\n");
	else if (mode == MEDIUM)
		ft_printf_strerr("Medium | O(n√n)\n");
	else if (mode == COMPLEX)
		ft_printf_strerr("Complex | O(n log n)\n");
	ft_printf_strerr("\n");
}

static int	sum_op(t_data *data)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += data->stats.count[i];
		i++;
	}
	return (total);
}

void	print_bench(t_data *data)
{
	ft_printf_strerr("[bench] disorder: %f%%\n", data->disorder * 100.0);
	ft_printf_strerr("[bench] strategy: ");
	print_mode(data->mode, data->disorder);
	ft_printf_strerr("[bench] total_ops: %i\n", sum_op(data));
	ft_printf_strerr("[bench] sa: %i sb: %i ss: %i ",
		data->stats.count[SA],
		data->stats.count[SB],
		data->stats.count[SS]);
	ft_printf_strerr("pa: %i pb: %i\n",
		data->stats.count[PA],
		data->stats.count[PB]);
	ft_printf_strerr("[bench] ra: %i rb: %i rr: %i ",
		data->stats.count[RA],
		data->stats.count[RB],
		data->stats.count[RR]);
	ft_printf_strerr("rra: %i rrb: %i rrr: %i\n",
		data->stats.count[RRA],
		data->stats.count[RRB],
		data->stats.count[RRR]);
}
