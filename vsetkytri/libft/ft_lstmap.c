/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaks <moaks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:47:30 by moaks             #+#    #+#             */
/*   Updated: 2026/09/02 19:16:14 by moaks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}

// void    *double_int(void *content)
// {
//     int *value;
//     int *result;

//     value = (int *)content;
//     result = malloc(sizeof(int));
//     if (!result)
//         return (NULL);
//     *result = (*value) * 2;
//     return (result);
// }

// void    del_int(void *content)
// {
//     free(content);
// }

// void    print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d ", *(int *)lst->content);
//         lst = lst->next;
//     }
//     printf("\n");
// }

// void    del_noop(void *content)
// {
//     (void)content;
// }

// int main(void)
// {
//     t_list  *lst;
//     t_list  *mapped;
//     int     values[5] = {1, 2, 3, 4, 5};
//     int     i;

//     lst = NULL;
//     i = 0;
//     while (i < 5)
//     {
//         ft_lstadd_back(&lst, ft_lstnew(&values[i]));
//         i++;
//     }

//     printf("Original list: ");
//     print_list(lst);

//     mapped = ft_lstmap(lst, double_int, del_int);

//     printf("Mapped list (x2): ");
//     print_list(mapped);

//     ft_lstclear(&lst, del_noop);   
//     ft_lstclear(&mapped, del_int);
//     return (0);
// }