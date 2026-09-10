#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_create_word(const char *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, size_t count)
{
	while (count > 0)
	{
		count--;
		free(split[count]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		i;
	size_t		start;
	size_t		word;

	if (s == NULL)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			split[word] = ft_create_word(&s[start], i - start);
			if (split[word] == NULL)
			{
				ft_free_split(split, word);
				return (NULL);
			}
			word++;
		}
	}
	split[word] = NULL;
	return (split);
}