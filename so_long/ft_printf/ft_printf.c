/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:19:49 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:19:50 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_format(const char *format, va_list arg, int *count)
{
	format++;
	if (*format == 'c')
		write_character(va_arg(arg, int), count);
	else if (*format == 'd')
		write_decimale(va_arg(arg, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (*format == 'u')
		write_uns_decimal(va_arg(arg, unsigned int), count);
	else if (*format == '%')
	{
		(*count)++;
		write(1, "%", 1);
	}
	else if (*format == 'i')
		write_int(va_arg(arg, int), count);
	else if (*format == 'p')
		write_hexa_add(va_arg(arg, void *), count);
	else if (*format == 'x')
		ft_print_hex_v2(va_arg(arg, unsigned int), count);
	else if (*format == 'X')
		ft_print_hex_v3(va_arg(arg, unsigned int), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if ((init_format(format)))
		{
			write_format(format, arg, &count);
			format++;
		}
		else
		{
			count++;
			ft_putchar_2(format);
		}
		format++;
	}
	va_end(arg);
	return (count);
}
