/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:17:38 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 17:09:29 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main()
// {
// 	printf("%i\n", ft_isalpha('A'-1));
// 	printf("%i\n", ft_isalpha('A'));
// 	printf("%i\n", ft_isalpha('z'));
// 	printf("%i\n", ft_isalpha('a'));
// 	printf("%i\n", ft_isalpha('Z'));
// 	printf("%i\n", ft_isalpha('Z' + 1));
// 	printf("%i\n", ft_isalpha(' '));
// 	printf("%i\n", ft_isalpha('0'));
// 	printf("%i\n", ft_isalpha('9'));
// 	printf("%i\n", ft_isalpha('@'));
// 	printf("%i\n", ft_isalpha('['));
// 	return 0;
// }