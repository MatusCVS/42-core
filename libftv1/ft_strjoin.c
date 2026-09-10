#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}