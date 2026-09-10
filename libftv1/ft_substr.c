#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = malloc(sizeof(char));
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}