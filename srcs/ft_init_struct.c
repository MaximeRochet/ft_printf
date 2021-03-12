/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:12:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 14:33:34 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_printf		*ft_init_struct(t_printf *stock)
{
	stock->reverse = 0;
	stock->zero = 0;
	stock->precision = 1;
	stock->range = 0;
	stock->negative = 0;
	stock->format = 0;
	stock->arg = NULL;
	return (stock);
}
