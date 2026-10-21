/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:28:15 by moaks             #+#    #+#             */
/*   Updated: 2026/09/03 16:06:01 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int	main()
// {
// 	printf("%i\n", ft_isprint('A'-1));
// 	printf("%i\n", ft_isprint('A'));
// 	printf("%i\n", ft_isprint('z'));
// 	printf("%i\n", ft_isprint('a'));
// 	printf("%i\n", ft_isprint('Z'));
// 	printf("%i\n", ft_isprint('Z' + 1));
// 	printf("%i\n", ft_isprint(' '));
// 	printf("%i\n", ft_isprint('0'));
// 	printf("%i\n", ft_isprint('9'));
// 	printf("%i\n", ft_isprint('@'));
// 	printf("%i\n", ft_isprint('['));
// 	printf("%i\n", ft_isprint(128));
// 	printf("%i\n", ft_isprint('~' + 1));
// 	return 0;
// }