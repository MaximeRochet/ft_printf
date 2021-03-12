/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:15:49 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 11:58:24 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_is_format(char c)
{
	char *convert;

	convert = "cspdiuxX%";
	while (*convert)
		if (c == *convert++)
			return (1);
	return (0);
}
