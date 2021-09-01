#include "ft_printf.h"

int	validate_data(const char *str)
{
	if (!str)
	{
		ft_putstr_fd("Format cannot be null", 1);
		return (-1);
	}
	return (0);
}

int	get_size(long value, long base)
{
	if (value > -base && value <= -1)
		return (2);
	if (value >= 0 && value < base)
		return (1);
	if (value < -base)
		return (2 + get_size(-value / base, base));
	return (1 + get_size(value / base, base));
}

int	process_conversion(const char *str, int index, va_list ap)
{
	if (str[index + 1] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (str[index + 1] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (str[index + 1] == 'd' || str[index + 1] == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (str[index + 1] == 'u')
		process_u_conv(va_arg(ap, int));
	else if (str[index + 1] == '%')
		ft_putchar_fd('%', 1);
	else if (str[index + 1] == 'x' || str[index + 1] == 'X')
		process_x_conv(va_arg(ap, int), str[index + 1]);
	else if (str[index + 1] == 'p')
		print_address_hex(va_arg(ap, void *));
	return (index + 1);
}

void	process_printing(va_list ap, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			i = process_conversion(str, i, ap);
		else
			ft_putchar_fd(str[i], 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	t_printf_env	*env;
	int				valid;

	va_start(ap, str);
	env = init_env();
	if (!env)
		return (-1);
	valid = validate_data(str);
	if (valid < 0)
		return (-1);
	process_printing(ap, str);
	va_end(ap);
	return (env->read_size);
}
