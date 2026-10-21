/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 12:51:11 by moaks             #+#    #+#             */
/*   Updated: 2026/09/04 15:56:19 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	res = malloc(len - i + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[i], len - i + 1);
	return (res);
}

// int	main()
// {
// 	printf("%s\n", ft_strtrim("wolrd hello world", "world"));
// 	return 0;
// }