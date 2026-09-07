#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
    size_t i;
    size_t j;
    size_t dest_len;

    dest_len = 0;
    while (dest_len < destsize && dest[dest_len] != '\0')
{
    dest_len++;
}
    if (dest_len == destsize)
    {
        return (destsize + ft_strlen(src));
    }
    i = dest_len;
    j = 0;
    while (src[j] != '\0' && i < destsize -1)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest_len + ft_strlen(src));
}