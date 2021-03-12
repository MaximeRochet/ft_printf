/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:32:51 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 14:25:08 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_launch_printf(t_printf *stock, va_list ap, const char *s)
{
	char		*flags;
	int			i;

	if (*s == '%')
	{
		i = 1;
		stock = ft_init_struct(stock);
		while (!(ft_is_format(s[i])))
			i++;
		flags = ft_substr(s, 1, i);
		if (!(ft_parser(stock, flags, ap)))
			return (0);
		ft_print_res(stock);
		ft_free_char(stock, flags);
		i++;
	}
	else
	{
		ft_putchar_fd(*s, 1);
		stock->len_result++;
		i = 1;
	}
	return (i);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	t_printf	*stock;
	int			i;
	int			len;

	va_start(ap, s);
	if (!(stock = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	stock->len_result = 0;
	while (*s)
	{
		if (!(i = ft_launch_printf(stock, ap, s)))
			return (-1);
		s += i;
	}
	len = stock->len_result;
	free(stock);
	va_end(ap);
	return (len);
}
