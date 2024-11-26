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

void	print_hex(unsigned int num, char c)
{
	if (num >= 16)
		print_hex(num / 16, c);
	if (c == 'X')
		ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
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

void	pad_width(int count, int target_width, char pad_char)
{
	while (count < target_width)
	{
		ft_putchar_fd(pad_char, 1);
		count++;
	}
}

void	hexadecimal_conversion(char c, va_list args, int *flags, int *width_precision)
{
	unsigned int	num;
	int				num_len;
	int				padding_len;

	num = va_arg(args, unsigned int);
	num_len = count_digits_hex(num);
	padding_len = 0;

	if (flags[3] == 1)
	{
		if (c == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		num_len += 2;
	}

	if (width_precision[1] > num_len)
		padding_len = width_precision[1] - num_len;

	if (flags[0] == 1)
	{
		pad_width(0, padding_len, '0');
		print_hex(num, c);
		pad_width(num_len + padding_len, width_precision[0], ' ');
	}
	else
	{
		if (flags[1] == 1)
			pad_width(num_len, width_precision[0], '0');
		else
			pad_width(num_len + padding_len, width_precision[0], ' ');

		pad_width(0, padding_len, '0');
		print_hex(num, c);
	}
}

