/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:36:51 by moaks             #+#    #+#             */
/*   Updated: 2026/09/19 15:37:25 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_hex(unsigned int i, char *digit, size_t base)
{
	int	count;

	count = 0;
	if (i >= base)
		count += ft_puthex(i / base, digit, base);
	return (count += ft_putchar(digit[i % base]));
}

static int	ft_specifier(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else if (specifier == 'x')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789abcdef", 16));
	else if (specifier == 'X')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789ABCDEF", 16));
	else if (specifier == 'u')
		return (ft_unsigned_hex(va_arg(args, int), "0123456789", 10));
	else if (specifier == 'p')
		return (ft_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	size_t	size;
	va_list	args;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_specifier(format[i], args);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
