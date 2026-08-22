#include <stdio.h>
int ft_iterative_factorial(int nb)

{
    int counter;
    int result;
    if (nb < 0)
        {
            return (0);
        }
        counter = nb;
        result = 1;
        while (counter > 1)
    {
        result = result * counter;
        counter--;
    }
    return (result);
}
/*
int	main(void)
{
	printf("5! = %d\n", ft_iterative_factorial(5));
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("1! = %d\n", ft_iterative_factorial(1));
	printf("-5! = %d\n", ft_iterative_factorial(-5));
	return (0);
}
*/