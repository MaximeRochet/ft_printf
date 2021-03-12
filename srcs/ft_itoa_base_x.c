/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:14:20 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/15 14:14:23 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_size(long int n, int base)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static char		*ft_itoa_base_x_spe(t_printf *stock)
{
	char		*res;

	if (stock->precision == 0)
	{
		if (!(res = (char *)malloc(sizeof(char))))
			return (0);
		res[0] = 0;
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * 2)))
		return (0);
	res[0] = '0';
	res[1] = 0;
	return (res);
}

char			*ft_itoa_base_x(unsigned n, char *str_base, t_printf *stock)
{
	char			*res;
	size_t			i_res;
	long long int	nbr;
	int				base;

	if (n == 0)
	{
		if (!(res = ft_itoa_base_x_spe(stock)))
			return (0);
		return (res);
	}
	nbr = (unsigned long)n;
	base = ft_strlen(str_base);
	i_res = ft_size(nbr, base);
	if (!(res = (char *)malloc(sizeof(char) * i_res + 1)))
		return (0);
	res[i_res] = 0;
	while (nbr > 0)
	{
		res[--i_res] = str_base[nbr % base];
		nbr /= base;
	}
	return (res);
}
