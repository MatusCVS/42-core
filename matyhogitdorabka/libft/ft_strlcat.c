/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:15:02 by moaks             #+#    #+#             */
/*   Updated: 2026/08/26 20:23:20 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	start;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size <= dest_len)
		return (size + src_len);
	start = 0;
	while (start < size - dest_len - 1 && src[start])
	{
		dst[dest_len + start] = src[start];
		start++;
	}
	dst[dest_len + start] = '\0';
	return (dest_len + src_len);
}

// int	main()
// {
// 	char dest[] = "pepa";
// 	char src[] = "je na piscine";
// 	unsigned int k;
// 	k = 9;
// 	unsigned int result;
// 	result = ft_strlcat(dest, src, k);
// 	printf("%i\n", result);
// 	printf("%s\n", dest);
// 	return (0);
// }