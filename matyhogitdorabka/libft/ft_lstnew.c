/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 18:19:36 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 18:28:25 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*arr_list;

	arr_list = (t_list *)malloc(sizeof(t_list));
	if (!arr_list)
		return (NULL);
	arr_list->content = content;
	arr_list->next = NULL;
	return (arr_list);
}

// int main()
// {
// 	int content1 = 42;
// 	t_list *node1 = ft_lstnew(&content1);

// 	if (!node1)
// 	{
// 		printf("%s\n", "Test 1 failed: Memory allocation error\n");
// 		return (1);
// 	}
// 	char *content2 = "hello";
// 	t_list *node2 = ft_lstnew(content2);

// 	if (!node2)
// 	{
// 		printf("%s\n", "Test 2 failed: Memory allocation error\n");
// 		return (1);
// 	}
// 	printf("Test 1: %p -> %d\n", (void *)node1, *(int *)node1 -> content);
// 	printf("Test 2: %p -> %s\n", (void *)node2, (char *)node2 -> content);

// 	free (node1);
// 	free (node2);
// 	return 0;
// }