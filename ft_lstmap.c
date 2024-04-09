/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:18:57 by kjung             #+#    #+#             */
/*   Updated: 2024/04/08 17:18:58 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;
    t_list  *cur;

    if (!lst)
        return (NULL);
    new = ft_lstnew((*f)(lst->content));
    if (!new)
        return (NULL);
    cur = new;
    lst = lst->next;
    while (lst)
    {
        if (!(cur->next = ft_lstnew((*f)(lst->content))))
        {
            ft_lstclear(&new, del);
            return (NULL);
        }
        cur = cur->next;
        lst = lst->next;
    }
    return (new);
}
