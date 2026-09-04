/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:16:57 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/09/04 18:16:59 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;
	unsigned char *ptr;

	i = 0;
	ptr = (unsigned char *)s;

	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
return (s);
}
