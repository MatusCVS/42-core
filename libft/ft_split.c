/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:38:41 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 17:26:32 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_size(char const *str, char c)
{
	size_t	size;
	int		in;

	size = 0;
	in = 0;
	while (*str)
	{
		if (*str != c && in == 0)
		{
			in = 1;
			size++;
		}
		else if (*str == c)
			in = 0;
		str++;
	}
	return (size);
}

static void	free_string_array(unsigned int j, char **result)
{
	while (j > 0)
		free(result[--j]);
	free(result);
	return ;
}

static void	assign(char const *str, char c, size_t count, char **result)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (str[i] == c)
			i++;
		k = 0;
		while (str[i + k] && str[i + k] != c)
			k++;
		result[j] = (char *)malloc(sizeof(char) * (k + 1));
		if (!result[j])
		{
			free_string_array(j, result);
			return ;
		}
		ft_strlcpy(result[j], &str[i], k + 1);
		i += k;
		j++;
	}
	result[j] = NULL;
}

char	**ft_split(char const *str, char c)
{
	size_t	size;
	char	**result;

	size = calculate_size(str, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	assign(str, c, size, result);
	return (result);
}

// int main ()
// {
// 	char **res;

// 	res = ft_split("hello.matty.rory", '.');
// 	printf("%s\n%s\n%s\n", res[0], res[1], res[2]);
// 	free_string_array(3, res);
// 	return 0;
// }