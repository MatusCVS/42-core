/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:14:48 by moaks             #+#    #+#             */
/*   Updated: 2026/10/14 23:01:52 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mode(char *argv1)
{
	if (ft_strncmp(argv1, "--bench", 8) == 0)
		return (BENCH);
	if (ft_strncmp(argv1, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(argv1, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(argv1, "--complex", 10) == 0)
		return (COMPLEX);
	if (ft_strncmp(argv1, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	return (NO_FLAG);
}
