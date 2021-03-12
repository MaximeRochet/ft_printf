/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:04:08 by mrochet           #+#    #+#             */
/*   Updated: 2020/12/03 12:38:13 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short		len_num(unsigned int n, short len)
{
	while ((n /= 10))
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*ret;
	short			size;
	unsigned int	nb;

	nb = n < 0 ? -n : n;
	size = len_num(nb, (n < 0 ? 2 : 1));
	if (!(ret = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[0] = n < 0 ? '-' : '0';
	ret[size] = '\0';
	while (nb > 0)
	{
		size--;
		ret[size] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}
