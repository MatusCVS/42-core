/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:35:24 by moaks             #+#    #+#             */
/*   Updated: 2026/09/19 15:35:46 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num >= 0 && num <= 9)
		count += ft_putchar(num + '0');
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

int	ft_puthex(unsigned long long int i, char *digit, size_t base)
{
	int	count;

	count = 0;
	if (i >= base)
		count += ft_puthex(i / base, digit, base);
	return (count += ft_putchar(digit[i % base]));
}

int	ft_pointer(void *pointer)
{
	if (pointer == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x")
		+ ft_puthex((unsigned long long int)pointer, "0123456789abcdef", 16));
}
