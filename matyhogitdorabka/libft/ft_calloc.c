/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:38:44 by moaks             #+#    #+#             */
/*   Updated: 2026/09/03 16:28:30 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((int)nmemb < 0 || (int)size < 0)
		return (NULL);
	array = (void *)malloc (size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return ((void *)array);
}
