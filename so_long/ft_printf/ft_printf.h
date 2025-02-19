/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:18:45 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:18:46 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		init_format(const char *format);
void	write_character(char c, int *count);
void	write_decimale(int i, int *count);
void	ft_putchar_2(const char *format);
void	ft_putstr(char *str, int *count);
void	ft_putchar(char c);
void	write_uns_decimal(unsigned int nbr, int *count);
void	write_int(int i, int *count);
void	ft_print_hex(unsigned long a, int *count);
void	write_hexa_add(void *ptr, int *count);
void	ft_print_hex_v2(unsigned int a, int *count);
void	ft_print_hex_v3(unsigned int a, int *count);
int		ft_printf(const char *format, ...);

#endif