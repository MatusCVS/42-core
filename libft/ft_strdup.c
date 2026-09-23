/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:59:29 by moaks             #+#    #+#             */
/*   Updated: 2026/09/03 16:42:24 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s1;
	size_t	size;

	size = sizeof(char) * (ft_strlen(src) + 1);
	s1 = (char *)malloc(size);
	if (!s1)
		return (NULL);
	i = 0;
	while (src[i])
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int main()
// {
// 	char *source = "hello";
// 	printf("%s\n", ft_strdup(source));
// 	return 0;
// }