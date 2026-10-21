/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:27:25 by moaks             #+#    #+#             */
/*   Updated: 2026/08/26 19:28:45 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main()
// {
// 	printf("%i\n", ft_isascii('A'-1));
// 	printf("%i\n", ft_isascii('A'));
// 	printf("%i\n", ft_isascii('z'));
// 	printf("%i\n", ft_isascii('a'));
// 	printf("%i\n", ft_isascii('Z'));
// 	printf("%i\n", ft_isascii('Z' + 1));
// 	printf("%i\n", ft_isascii(' '));
// 	printf("%i\n", ft_isascii('0'));
// 	printf("%i\n", ft_isascii('9'));
// 	printf("%i\n", ft_isascii('@'));
// 	printf("%i\n", ft_isascii('['));
// 	printf("%i\n", ft_isascii(128));
// 	printf("%i\n", ft_isascii(0));
// 	printf("%i\n", ft_isascii(300));
// 	printf("%i\n", ft_isascii(35));
// 	printf("%i\n", ft_isascii(0 - 1));
// 	return 0;
// }