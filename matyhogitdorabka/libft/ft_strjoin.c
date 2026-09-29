/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 12:27:04 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 17:25:09 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len + 1);
	ft_strlcat(s3, s2, len + 1);
	return (s3);
}

// int main()
// {
// 	char	*prefix;
// 	char	*suffix;
// 	char	*result;

// 	prefix = "rory";
// 	suffix = "matty";
// 	result = ft_strjoin(prefix, suffix);
// 	printf("%s\n", result); 
// 	free(result);
// 	return 0;
// }