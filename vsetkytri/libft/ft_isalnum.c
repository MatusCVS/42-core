/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:13:55 by moaks             #+#    #+#             */
/*   Updated: 2026/08/26 19:35:40 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1)
		return (1);
	if (ft_isalpha(c) == 1)
		return (1);
	return (0);
}

// int	main()
// {
// 	printf("%i\n", ft_isalnum('A'-1));
// 	printf("%i\n", ft_isalnum('A'));
// 	printf("%i\n", ft_isalnum('z'));
// 	printf("%i\n", ft_isalnum('a'));
// 	printf("%i\n", ft_isalnum('Z'));
// 	printf("%i\n", ft_isalnum('Z' + 1));
// 	printf("%i\n", ft_isalnum(' '));
// 	printf("%i\n", ft_isalnum('0'));
// 	printf("%i\n", ft_isalnum('9'));
// 	printf("%i\n", ft_isalnum('@'));
// 	printf("%i\n", ft_isalnum('['));
// 	return 0;
// }