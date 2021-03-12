/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:14:11 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/09 11:34:41 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_fill_bool(t_printf *stock, char *s)
{
	while (*s == '0' || *s == '-')
	{
		if (*s == '-')
		{
			stock->reverse = 1;
			stock->zero = 0;
		}
		if (*s == '0' && !(stock->reverse))
			stock->zero = 1;
		s++;
	}
}

int			ft_fill_range(t_printf *stock, char *s, va_list ap, char *range)
{
	int			i;

	while ((!(ft_isdigit(*s)) || *s == '0') && *s != '*' \
	&& *s != '.' && !(ft_is_format(*s)))
		s++;
	if (*s == '*')
	{
		stock->range = va_arg(ap, int);
		if (stock->range < 0)
		{
			stock->range *= -1;
			stock->reverse = 1;
			stock->zero = 0;
		}
	}
	else if (ft_isdigit(*s) && !(i = 0))
	{
		while (ft_isdigit(s[i]))
			i++;
		if (!(range = ft_substr(s, 0, i)))
			return (0);
		stock->range = ft_atoi(range);
		free(range);
	}
	return (1);
}

int			ft_fill_precision_annex(t_printf *stock, char *s, va_list ap)
{
	char		*precision;
	int			i;

	i = 1;
	if (s[i] == '*')
	{
		if ((stock->precision = va_arg(ap, int)) < 0)
			stock->precision = -24;
		i++;
	}
	else if (ft_isdigit(s[i]))
	{
		while (ft_isdigit(s[i]))
			i++;
		if (!(precision = ft_substr(s, 1, i)))
			return (0);
		stock->precision = ft_atoi(precision);
		free(precision);
	}
	else
		stock->precision = 0;
	return (i);
}

int			ft_fill_precision(t_printf *stock, char *s, va_list ap)
{
	int			i;

	while (!(ft_is_format(*s)) && *s != '.')
		s++;
	if (*s == '.')
	{
		if (!(i = ft_fill_precision_annex(stock, s, ap)))
			return (0);
		s += i;
		if (stock->format != 's' && stock->precision != -24)
			stock->zero = 0;
		if (stock->precision < 0 && *s == 's')
			stock->precision = -42;
	}
	else
	{
		if (*s == 's')
			stock->precision = -42;
	}
	stock->format = *s;
	return (1);
}

int			ft_parser(t_printf *stock, char *flags, va_list ap)
{
	char		*range;

	range = NULL;
	ft_fill_bool(stock, flags);
	if (!(ft_fill_range(stock, flags, ap, range)))
		return (0);
	if (!(ft_fill_precision(stock, flags, ap)))
		return (0);
	if (!(ft_fill_arg(stock, ap)))
		return (0);
	return (1);
}
