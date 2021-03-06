/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:26:58 by lmaujean          #+#    #+#             */
/*   Updated: 2021/08/31 11:28:38 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_address_hex(void *ptr, t_printf_env *env)
{
	int			i;
	int			j;
	int64_t		p;
	char		c;
	char		*addr;

	p = (int64_t)ptr;
	i = 64;
	addr = malloc(16);
	j = 0;
	while (i >= 0)
	{
		c = hex_digit((p >> i) & 0xf);
		addr[j++] = c;
		i -= 4;
	}
	j = 0;
	write(1, "0x", 2);
	while (addr[j] == '0')
		j++;
	while (addr[j])
	{
		write(1, &addr[j++], 1);
		env->read_size += 1;
	}	
}

void	*init_env(void)
{
	t_printf_env	*env;

	env = malloc(sizeof(t_printf_env));
	if (!env)
		ft_putstr_size("Malloc allocation failed", 1, env);
	return (env);
}

void	process_u_conv(int nb, t_printf_env *env)
{
	unsigned int	unsigned_nb;

	unsigned_nb = nb;
	ft_putnbr_unsigned(unsigned_nb, env);
}

void	process_x_conv(int nb, char conv, t_printf_env *env)
{
	char	*ret;
	int		i;

	ret = ft_itoa_base(nb, 16);
	i = -1;
	if (conv == 'x')
		while (ret[++i])
		{
			ret[i] = ft_tolower(ret[i]);
			env->read_size += 1;
		}	
	ft_putstr_fd(ret, 1);
}
