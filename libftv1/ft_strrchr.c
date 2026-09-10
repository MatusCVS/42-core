/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:17:56 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/09/07 22:17:57 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[0] == (char)c)
		return ((char *)&s[0]);
	return (NULL);
}