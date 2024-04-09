/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:18:49 by kjung             #+#    #+#             */
/*   Updated: 2024/04/08 17:18:50 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *cur;

    while (*lst)
    {
        cur = *lst;
        *lst = (*lst)->next;
        ft_lstdelone(cur, del);
    }
    *lst = NULL;
}
