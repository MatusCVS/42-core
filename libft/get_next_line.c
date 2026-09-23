/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:24:59 by moaks             #+#    #+#             */
/*   Updated: 2026/09/19 15:29:00 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *rest, char *buffer)
{
	ssize_t	text;
	char	*temp;

	text = 1;
	while (text > 0)
	{
		text = read(fd, buffer, BUFFER_SIZE);
		if (text == -1)
		{
			free(rest);
			return (NULL);
		}
		else if (text == 0)
			return (rest);
		buffer[text] = 0;
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			return (rest);
	}
	return (rest);
}

static char	*handle_rest(char *line)
{
	char	*rest;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	line[i + 1] = 0;
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = read_line(fd, rest, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest = handle_rest(line);
	return (line);
}
