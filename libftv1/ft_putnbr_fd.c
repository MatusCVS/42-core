#include "libft.h"

static void	ft_putlong_fd(long number, int fd)
{
	if (number >= 10)
		ft_putlong_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = -number;
	}
	ft_putlong_fd(number, fd);
}