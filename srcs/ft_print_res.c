/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:15:17 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 14:39:20 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			ft_print_arg_s(t_printf *stock, int len_res)
{
	if (stock->precision < len_res)
	{
		stock->arg[stock->precision] = '\0';
		ft_putstr_fd(stock->arg, 1);
	}
	else
		ft_putstr_fd(stock->arg, 1);
}

void			ft_print_arg_p(t_printf *stock, int len_res)
{
	int			i;

	if (stock->precision > len_res)
	{
		i = -1;
		ft_putstr_fd("0x", 1);
		while (++i < stock->precision - len_res)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(stock->arg, 1);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(stock->arg, 1);
	}
}

void			ft_print_arg(t_printf *stock, int len_res)
{
	int			i;

	if (stock->format == 'c')
		ft_putchar_fd(stock->arg[0], 1);
	else if (stock->format == 's')
		ft_print_arg_s(stock, len_res);
	else if (stock->format == 'p')
		ft_print_arg_p(stock, len_res);
	else
	{
		if (stock->negative)
			ft_putchar_fd('-', 1);
		if (stock->precision > len_res)
		{
			i = -1;
			while (++i < stock->precision - len_res)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(stock->arg, 1);
		}
		else
			ft_putstr_fd(stock->arg, 1);
	}
}

void			ft_print_range(t_printf *stock, int len_res_final)
{
	int			i;

	if (stock->negative && stock->zero)
	{
		ft_putchar_fd('-', 1);
		stock->negative = 0;
	}
	if (stock->range > len_res_final)
	{
		i = 0;
		while (i < stock->range - len_res_final)
		{
			if (stock->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
		stock->len_result += i;
	}
}

void			ft_print_res(t_printf *stock)
{
	int			len_res;
	int			len_res_final;

	len_res = ft_strlen(stock->arg);
	len_res_final = ft_len_res_final(stock, len_res);
	if (stock->negative)
		len_res_final++;
	stock->len_result += len_res_final;
	if (stock->reverse)
	{
		ft_print_arg(stock, len_res);
		ft_print_range(stock, len_res_final);
	}
	else
	{
		ft_print_range(stock, len_res_final);
		ft_print_arg(stock, len_res);
	}
}
