/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:05:13 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/09/04 21:05:15 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	const unsigned char *ptrsrc;
	size_t i;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (const unsigned char *)src;

	i = n;

	if (dest == src)
	{
		return (dest);
	}
	else if (ptrdest < ptrsrc)
	{
		return (ft_memcpy(dest, src, n));
	}
	while (i > 0)
	{
		i--;
	
		ptrdest[i] = ptrsrc[i];
	}
	return (dest);
}
