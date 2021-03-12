/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:14:43 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/16 16:54:18 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ft_strdup_null(const char *useless)
{
	char		*new_s;

	(void)useless;
	if (!(new_s = (char*)malloc(sizeof(char) * 7)))
		return (0);
	new_s[0] = '(';
	new_s[1] = 'n';
	new_s[2] = 'u';
	new_s[3] = 'l';
	new_s[4] = 'l';
	new_s[5] = ')';
	new_s[6] = 0;
	return (new_s);
}

char			*ft_strdup_spe(const char *s1)
{
	size_t		size;
	size_t		i_s;
	char		*new_s;

	if (!s1)
	{
		if (!(new_s = ft_strdup_null(s1)))
			return (0);
		return (new_s);
	}
	size = ft_strlen(s1);
	i_s = 0;
	if (!(new_s = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	while (i_s < size)
	{
		new_s[i_s] = s1[i_s];
		i_s++;
	}
	new_s[i_s] = '\0';
	if (new_s == NULL)
		return (0);
	return (new_s);
}
