/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:04:14 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 11:04:17 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(int n, char *str_base)
{
	long long int	llong_n;
	int				base;

	llong_n = n;
	base = ft_strlen(str_base);
	if (llong_n < 0)
	{
		ft_putchar_fd('-', 1);
		llong_n = llong_n * (-1);
	}
	if (llong_n < base)
	{
		ft_putchar_fd(str_base[llong_n], 1);
	}
	else
	{
		ft_putnbr_base(llong_n / base, str_base);
		ft_putnbr_base(llong_n % base, str_base);
	}
}
