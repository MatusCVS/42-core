#include <stdio.h>

int ft_sqrt(int nb)

{
    int result;
    if (nb < 0)
        {
            return (0);
        }
        if ( nb == 0 || nb == 1)
    {
        return (nb);
    }
   result = 1;
	while (result <= nb / result)
	{
		if (result * result == nb)
		{
			return (result);
		}
		result++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_sqrt(2));
	return (0);
}
*/