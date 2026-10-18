/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stderr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiklovi <mmiklovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:31:19 by mmiklovi          #+#    #+#             */
/*   Updated: 2026/10/18 13:31:20 by mmiklovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_double_fd(double n, int fd)
{
	int			i;
	long long	whole;
	double		frac;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	whole = (long long)n;
	frac = n - (double)whole;
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	i = 0;
	while (i < 2)
	{
		frac *= 10;
		ft_putchar_fd(('0' + (int)frac % 10), 2);
		i++;
	}
	return (0);
}

static int	ft_specifier(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), 2));
	else if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), 2));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 2));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 2));
	else if (specifier == 'f')
		return (ft_double_fd(va_arg(args, double), 2));
	return (0);
}

int	ft_printf_strerr(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_specifier(format[i], args);
		}
		else
			ft_putchar_fd(format[i], 2);
		i++;
	}
	va_end(args);
	return (0);
}
