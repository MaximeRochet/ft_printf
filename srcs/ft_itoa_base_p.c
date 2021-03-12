/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:13:11 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/15 14:13:14 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t		ft_size(unsigned long n, int base)
{
	size_t			size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char				*ft_itoa_base_p(unsigned long nbr, char *str_base)
{
	char			*res;
	size_t			i_res;
	int				base;

	base = ft_strlen(str_base);
	i_res = ft_size(nbr, base);
	if (!(res = (char *)malloc(sizeof(char) * i_res + 1)))
		return (0);
	res[i_res] = 0;
	if (nbr == 0)
		res[0] = '0';
	while (nbr > 0)
	{
		res[--i_res] = str_base[nbr % base];
		nbr /= base;
	}
	return (res);
}
