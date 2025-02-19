/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:03:56 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:03:59 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Count the number of digits of an int */
int	ft_digitcount(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

/* Count the number of digits that an int has in hexadecimal */
int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

/* Count the number of digits that an int has in long hexadecimal */
int	ft_hexlen_long(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}
