/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:51:55 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 17:14:17 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = c;
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char *str;
// 	str = strdup("hello");
// 	ft_memset(str, 'x', 5);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
// kastovani