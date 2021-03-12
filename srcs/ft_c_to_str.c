/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:12:35 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/15 14:12:39 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char			*ft_c_to_str(int c)
{
	char		*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	new_str[0] = c;
	new_str[1] = '\0';
	return (new_str);
}
