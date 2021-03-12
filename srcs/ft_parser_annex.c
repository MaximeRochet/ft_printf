/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_annex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:16:08 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/09 11:36:09 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_fill_arg_annex(t_printf *stock, va_list ap)
{
	if (stock->format == 'u')
		if (!(stock->arg = ft_itoa_base_u(va_arg(ap, unsigned int),\
		"0123456789", stock)))
			return (0);
	if (stock->format == 's')
		if (!(stock->arg = ft_strdup_spe(va_arg(ap, char *))))
			return (0);
	if (stock->format == 'c')
		if (!(stock->arg = ft_c_to_str(va_arg(ap, int))))
			return (0);
	if (stock->format == '%')
		if (!(stock->arg = ft_c_to_str('%')))
			return (0);
	return (1);
}

int				ft_fill_arg(t_printf *stock, va_list ap)
{
	if (stock->format == 'd' || stock->format == 'i')
		if (!(stock->arg = ft_itoa_int(va_arg(ap, int), stock)))
			return (0);
	if (stock->format == 'x')
		if (!(stock->arg = ft_itoa_base_x(va_arg(ap, unsigned), \
		"0123456789abcdef", stock)))
			return (0);
	if (stock->format == 'X')
		if (!(stock->arg = ft_itoa_base_x(va_arg(ap, unsigned), \
		"0123456789ABCDEF", stock)))
			return (0);
	if (stock->format == 'p')
		if (!(stock->arg = ft_itoa_base_p(va_arg(ap, unsigned long),\
		"0123456789abcdef")))
			return (0);
	if (stock->format == 'u' || stock->format == 's' \
	|| stock->format == 'c' || stock->format == '%')
		if (!(ft_fill_arg_annex(stock, ap)))
			return (0);
	return (1);
}
