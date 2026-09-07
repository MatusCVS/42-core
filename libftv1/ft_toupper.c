#include "libft.h"

int ft_toupper(int c)
{
    if (c <= 122 && c >= 97)
    {
        c = c -32;
    }
    return (c);
}