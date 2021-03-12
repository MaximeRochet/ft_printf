/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:32:09 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/08 14:31:19 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include "../libft/libft.h"

typedef struct	s_printf
{
	unsigned	len_result;
	int			reverse;
	int			zero;
	int			precision;
	int			range;
	int			negative;
	char		format;
	char		*arg;
}				t_printf;

int				ft_printf(const char *str, ...) __attribute__
				((format(printf,1,2)));
int				ft_launch_printf(t_printf *stock, va_list ap, const char *s);

t_printf		*ft_init_struct(t_printf *stock);
int				ft_is_format(char c);

int				ft_parser(t_printf *stock, char *flags, va_list ap);

void			ft_fill_bool(t_printf *stock, char *s);
int				ft_fill_range(t_printf *stock, char *s,\
				va_list ap, char *range);
int				ft_fill_precision(t_printf *stock, char *s, va_list ap);
int				ft_fill_precision_annex(t_printf *stock, char *s, va_list ap);
int				ft_fill_arg(t_printf *stock, va_list ap);
int				ft_fill_arg_annex(t_printf *stock, va_list ap);

char			*ft_itoa_int(int n, t_printf *stock);
char			*ft_itoa_base_x(unsigned n, char *str_base, t_printf *stock);
char			*ft_itoa_base_p(unsigned long nbr, char *str_base);
char			*ft_itoa_base_u(unsigned nbr, char *str_base, t_printf *stock);
char			*ft_strdup_spe(const char *s1);
char			*ft_c_to_str(int c);

void			ft_print_res(t_printf *stock);

int				ft_len_res_final(t_printf *stock, int len_res);
int				ft_len_s(t_printf *stock, int len_res);
int				ft_len_p(t_printf *stock, int len_res);
int				ft_len_rest(t_printf *stock, int len_res);
int				ft_len_res_final(t_printf *stock, int len_res);

void			ft_print_range(t_printf *stock, int len_res_final);

void			ft_print_arg(t_printf *stock, int len_res);
void			ft_print_arg_s(t_printf *stock, int len_res);
void			ft_print_arg_p(t_printf *stock, int len_res);

void			ft_free_char(t_printf *stock, char *flags);

#endif
