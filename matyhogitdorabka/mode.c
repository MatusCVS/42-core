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

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int get_mode(char *argv1)
{
    if (ft_strcmp(argv1, "--bench"))
        return (BENCH);
    if (ft_strcmp(argv1, "--simple"))
        return (SIMPLE);
    if (ft_strcmp(argv1, "--medium"))
        return (MEDIUM);
    if (ft_strcmp(argv1, "--complex"))
        return (COMPLEX);
    if (ft_strcmp(argv1, "--adaptive"))
        return (ADAPTIVE);
    return (NO_FLAG);
}
