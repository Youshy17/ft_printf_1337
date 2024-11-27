/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:42 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/27 09:48:24 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_dec(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count = 1;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	integer_conversion(va_list args, int *flags, int *width_precision)
{
	int	temp;
	int	digits;
	int	sign_len;
	int	padding;
	int	count;

	temp = va_arg(args, int);
	digits = count_digits_dec(temp);
	sign_len = 0;
	count = 0;
	if (temp >= 0 && (flags[4] == 1 || flags[5] == 1))
		sign_len = 1;

	if (temp < 0)
	{
		if (width_precision[1] > digits - 1)
			padding = width_precision[1] - (digits - 1);
		else
			padding = 0;
	}
	else
	{
		if (width_precision[1] > digits)
			padding = width_precision[1] - digits;
		else
			padding = 0;
	}

	if (flags[0] == 1)
	{
		if (temp >= 0 && flags[5])
			count += ft_putchar_fd('+', 1);
		else if (temp >= 0 && flags[4])
			count += ft_putchar_fd(' ', 1);
		if (temp < 0)
			count += ft_putchar_fd('-', 1);

		while (padding > 0)
		{
			count += ft_putchar_fd('0', 1);
			padding--;
		}

		if (temp < 0 && temp == -2147483648)
			count += ft_putstr_fd("2147483648", 1);
		else if (temp < 0)
			count += ft_putnbr_fd(-temp, 1);
		else
			count += ft_putnbr_fd(temp, 1);

		while (digits + sign_len + padding < width_precision[0])
		{
			count += ft_putchar_fd(' ', 1);
			digits++;
		}
		return (count);
	}

	if (flags[1] == 1 && flags[2] == 0)
	{
		if (temp >= 0 && flags[5] == 1)
			count += ft_putchar_fd('+', 1);
		else if (temp >= 0 && flags[4] == 1)
			count += ft_putchar_fd(' ', 1);
		if (temp < 0)
			count += ft_putchar_fd('-', 1);

		while (digits + sign_len < width_precision[0])
		{
			count += ft_putchar_fd('0', 1);
			digits++;
		}

		if (temp < 0 && temp == -2147483648)
			count += ft_putstr_fd("2147483648", 1);
		else if (temp < 0)
			count += ft_putnbr_fd(-temp, 1);
		else
			count += ft_putnbr_fd(temp, 1);

		return (count);
	}

	while (digits + sign_len + padding < width_precision[0])
	{
		count += ft_putchar_fd(' ', 1);
		digits++;
	}

	if (temp >= 0 && flags[5] == 1)
		count += ft_putchar_fd('+', 1);
	else if (temp >= 0 && flags[4] == 1)
		count += ft_putchar_fd(' ', 1);
	if (temp < 0)
		count += ft_putchar_fd('-', 1);

	while (padding > 0)
	{
		count += ft_putchar_fd('0', 1);
		padding--;
	}

	if (temp < 0 && temp == -2147483648)
		count += ft_putstr_fd("2147483648", 1);
	else if (temp < 0)
		count += ft_putnbr_fd(-temp, 1);
	else
		count += ft_putnbr_fd(temp, 1);

	return (count);
}
