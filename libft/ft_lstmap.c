/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:16:54 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/01 12:06:12 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (lst)
	{
		begin = NULL;
		new = begin;
		while (lst)
		{
			new = ft_lstnew((*f)(lst->content));
			if (!new)
			{
				ft_lstclear(&begin, (*del));
				return (NULL);
			}
			ft_lstadd_back(&begin, new);
			lst = lst->next;
		}
		return (begin);
	}
	return (NULL);
}
