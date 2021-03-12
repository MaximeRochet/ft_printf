/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_res_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:16:41 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 14:36:52 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_len_s(t_printf *stock, int len_res)
{
	int			len_res_final;

	if (stock->precision < len_res && stock->precision != -42)
		len_res_final = stock->precision;
	else
	{
		stock->precision = len_res;
		len_res_final = len_res;
	}
	return (len_res_final);
}

int				ft_len_p(t_printf *stock, int len_res)
{
	int			len_res_final;

	if (stock->precision > len_res)
		len_res_final = stock->precision + 2;
	else
		len_res_final = len_res + 2;
	return (len_res_final);
}

int				ft_len_rest(t_printf *stock, int len_res)
{
	int			len_res_final;

	if (stock->precision > len_res)
		len_res_final = stock->precision;
	else
		len_res_final = len_res;
	return (len_res_final);
}

int				ft_len_res_final(t_printf *stock, int len_res)
{
	int			len_res_final;

	if (stock->format == 's')
	{
		len_res_final = ft_len_s(stock, len_res);
	}
	else if (stock->format == 'p')
	{
		len_res_final = ft_len_p(stock, len_res);
	}
	else
	{
		len_res_final = ft_len_rest(stock, len_res);
	}
	return (len_res_final);
}
