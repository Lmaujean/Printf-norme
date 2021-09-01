/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:21:51 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/14 11:39:43 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <limits.h>

typedef struct s_printf_env
{
	size_t		read_size;
}				t_printf_env;

void		print_address_hex(void *ptr);
void		*init_env(void);
void		process_u_conv(int nb);
void		process_x_conv(int nb, char conv);
void		ft_putnbr_unsigned(unsigned int n);
char		*ft_itoa_base(int value, int base);
char		hex_digit(int v);
int			validate_data(const char *str);
int			get_size(long value, long base);
int			process_conversion(const char *str, int index, va_list ap);
void		process_printing(va_list ap, const char *str);
void		ft_putchar_size(char c, t_printf_env *env);
int			ft_printf(const char *str, ...);

#endif