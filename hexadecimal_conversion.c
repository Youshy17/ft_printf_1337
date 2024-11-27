/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:35 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:07:36 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int num, char c)
{
	int count;

	count = 0;
	if (num >= 16)
		count += print_hex(num / 16, c);
	if (c == 'X')
		count += ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	else
		count += ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	return (count);
}

int	count_digits_hex(unsigned int nbr)
{
	int	count = 0;

	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	pad_width(int n, int target_width, char pad_char)
{
	int count;

	count = 0;
	while (n < target_width)
	{
		count += ft_putchar_fd(pad_char, 1);
		count++;
	}
	return (count);
}

int	hexadecimal_conversion(char c, va_list args, int *flags, int *width_precision)
{
	unsigned int	num;
	int				num_len;
	int				padding_len;
	int				count;

	num = va_arg(args, unsigned int);
	num_len = count_digits_hex(num);
	padding_len = 0;
	count = 0;

	if (flags[3] == 1)
	{
		if (c == 'x')
			count += ft_putstr_fd("0x", 1);
		else
			count += ft_putstr_fd("0X", 1);
		num_len += 2;
	}

	if (width_precision[1] > num_len)
		padding_len = width_precision[1] - num_len;

	if (flags[0] == 1)
	{
		count += pad_width(0, padding_len, '0');
		count += print_hex(num, c);
		count += pad_width(num_len + padding_len, width_precision[0], ' ');
	}
	else
	{
		if (flags[1] == 1)
			count += pad_width(num_len, width_precision[0], '0');
		else
			count += pad_width(num_len + padding_len, width_precision[0], ' ');

		count += pad_width(0, padding_len, '0');
		count += print_hex(num, c);
	}
	return (count);
}

