/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:17:15 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/15 14:17:17 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_size(long int n)
{
	size_t		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char		*ft_itoa_int_spe(t_printf *stock)
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

long int		ft_is_negative(t_printf *stock, long int nbr)
{
	stock->negative = 1;
	nbr *= -1;
	return (nbr);
}

char			*ft_itoa_int(int n, t_printf *stock)
{
	char		*res;
	size_t		i_res;
	long int	nbr;

	if (n == 0)
	{
		if (!(res = ft_itoa_int_spe(stock)))
			return (0);
		return (res);
	}
	nbr = (long int)n;
	i_res = ft_size(nbr);
	if (!(res = (char *)malloc(sizeof(char) * i_res + 1)))
		return (0);
	if (nbr < 0)
		nbr = ft_is_negative(stock, nbr);
	res[i_res] = 0;
	while (nbr > 0)
	{
		res[--i_res] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}
