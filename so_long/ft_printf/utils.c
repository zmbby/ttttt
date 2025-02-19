/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:18:20 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:18:39 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_int(int i, int *count)
{
	long	nbr;

	nbr = i;
	if (nbr < 0)
	{
		(*count)++;
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		write_int(nbr / 10, count);
		nbr = nbr % 10;
	}
	(*count)++;
	ft_putchar(nbr + 48);
}

void	ft_print_hex(unsigned long a, int *count)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (a >= 16)
	{
		ft_print_hex(a / 16, count);
		a = a % 16;
	}
	(*count)++;
	ft_putchar(base_hex[a]);
}

void	write_hexa_add(void *ptr, int *count)
{
	unsigned long	add;

	add = (unsigned long)ptr;
	if (add == 0)
		(*count) += write(1, "(nil)", 5);
	else
	{
		(*count) += 2;
		write(1, "0x", 2);
		ft_print_hex(add, count);
	}
}

void	ft_print_hex_v2(unsigned int a, int *count)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (a >= 16)
	{
		ft_print_hex_v2(a / 16, count);
		a = a % 16;
	}
	(*count)++;
	ft_putchar(base_hex[a]);
}

void	ft_print_hex_v3(unsigned int a, int *count)
{
	char	*base_hex;

	base_hex = "0123456789ABCDEF";
	if (a >= 16)
	{
		ft_print_hex_v3(a / 16, count);
		a = a % 16;
	}
	(*count)++;
	ft_putchar(base_hex[a]);
}
