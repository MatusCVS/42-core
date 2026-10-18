/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/10/15 17:52:35 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mode(char *argv)
{
	if (ft_strncmp(argv, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(argv, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(argv, "--complex", 10) == 0)
		return (COMPLEX);
	if (ft_strncmp(argv, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	return (NO_FLAG);
}

int	get_bench(char *argv)
{
	if (ft_strncmp(argv, "--bench", 8) == 0)
		return (TRUE);
	return (FALSE);
}

void	count_op(t_stack *s, t_op op)
{
	if (s->bench)
		s->bench->count[op]++;
}

int	parse_flags(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (get_bench(argv[i]) == TRUE)
			data->bench = TRUE;
		else if (get_mode(argv[i]) != NO_FLAG)
			data->mode = get_mode(argv[i]);
		else
			return (-1);
		i++;
	}
	return (i);
}
