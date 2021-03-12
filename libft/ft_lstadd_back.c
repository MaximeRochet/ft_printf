/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:38:53 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/01 11:10:23 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last_elem;

	if (alst)
	{
		if (!*alst)
		{
			*alst = new;
			return ;
		}
		last_elem = ft_lstlast(*alst);
		last_elem->next = new;
	}
}
