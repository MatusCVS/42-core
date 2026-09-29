/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:20:30 by moaks             #+#    #+#             */
/*   Updated: 2026/08/27 14:16:36 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main()
// {
// 	printf("%i\n", ft_isdigit('0'-1));
// 	printf("%i\n", ft_isdigit('A'));
// 	printf("%i\n", ft_isdigit('z'));
// 	printf("%i\n", ft_isdigit('8'));
// 	printf("%i\n", ft_isdigit('Z'));
// 	printf("%i\n", ft_isdigit('9' + 1));
// 	printf("%i\n", ft_isdigit(' '));
// 	printf("%i\n", ft_isdigit('0'));
// 	printf("%i\n", ft_isdigit('9'));
// 	printf("%i\n", ft_isdigit('@'));
// 	printf("%i\n", ft_isdigit('['));
// 	return 0;
// }