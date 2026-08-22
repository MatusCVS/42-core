#include <stdio.h>
int ft_recursive_factorial(int nb)

{
    int result;
    if (nb < 0)
        {
            return (0);
        }
        if ( nb == 0 || nb == 1)
    {
        return (1);
    }
    result = nb * ft_recursive_factorial(nb - 1);
    return (result);
}
/*
int	main(void)
{
	printf("5! = %d\n", ft_recursive_factorial(5));
	printf("0! = %d\n", ft_recursive_factorial(0));
	printf("1! = %d\n", ft_recursive_factorial(1));
	printf("-5! = %d\n", ft_recursive_factorial(-5));
	return (0);
}
*/