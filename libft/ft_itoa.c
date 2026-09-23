/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:32:05 by moaks             #+#    #+#             */
/*   Updated: 2026/09/03 15:59:07 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_size(long long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(*str), size + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char			*dst;
	size_t			count;
	size_t			i;
	long long int	num;

	num = (long long int)n;
	count = count_size(num);
	i = 0;
	if (num < 0 || count == 0)
		count++;
	dst = ft_strnew(count);
	if (!dst)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		dst[0] = '-';
		i++;
	}
	while (count-- > i)
	{
		dst[count] = (num % 10) + '0';
		num /= 10;
	}
	return (dst);
}

// int	main()
// {
// 	char	*a, *b, *c, *d, *e;
// 	a = ft_itoa(-2147483648);
// 	b = ft_itoa(2147483647);
// 	c = ft_itoa(0);
// 	d = ft_itoa(42);
// 	e = ft_itoa(-42);
// 	printf("%s\n", a);
// 	printf("%s\n", b);
// 	printf("%s\n", c);
// 	printf("%s\n", d);
// 	printf("%s\n", e);
// 	free(a);
// 	free(b);
// 	free(c);
// 	free(d);
// 	free(e);
// }