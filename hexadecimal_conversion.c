/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:35 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 18:09:18 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad_width(int n, int target_width, char pad_char)
{
	int	count;

	count = 0;
	while (n++ < target_width)
		count += ft_putchar_fd(pad_char, 1);
	return (count);
}

int	hexadecimal_conversion_bis_two(char c, int *flags, int *width_precision,
		int *comb)
{
	int	count;

	count = 0;
	if (flags[1] == 1 && flags[2] == 0)
		count += pad_width(0, width_precision[0], '0');
	else
		count += pad_width(0, width_precision[0], ' ');
	if (comb[1] > 0)
	{
		if (c == 'x')
			count += ft_putstr_fd("0x", 1);
		else
			count += ft_putstr_fd("0X", 1);
	}
	count += pad_width(0, width_precision[1], '0');
	if (comb[2] > 0)
		count += print_hex(comb[0], c);
	return (count);
}

int	hexadecimal_conversion_bis_one(char c, int *flags, int *width_precision,
		int *comb)
{
	int	count;

	count = 0;
	if (flags[0] == 1)
	{
		if (comb[1] > 0)
		{
			if (c == 'x')
				count += ft_putstr_fd("0x", 1);
			else
				count += ft_putstr_fd("0X", 1);
		}
		count += pad_width(0, width_precision[1], '0');
		if (comb[2] > 0)
			count += print_hex(comb[0], c);
		count += pad_width(0, width_precision[0], ' ');
	}
	else
		count += hexadecimal_conversion_bis_two(c, flags, width_precision,
				comb);
	return (count);
}

void	combine_vars(int *comb, int num, int prefix_len, int num_len)
{
	comb[0] = num;
	comb[1] = prefix_len;
	comb[2] = num_len;
}

int	hexadecimal_conversion(char c, va_list args, int *flags,
		int *width_precision)
{
	unsigned int	num;
	int				num_len;
	int				count;
	int				prefix_len;
	int				comb[3];

	num = va_arg(args, unsigned int);
	count = 0;
	if (num == 0 && flags[2] && width_precision[1] == 0)
		num_len = 0;
	else
		num_len = count_digits_hex(num);
	if (flags[3] == 1 && num != 0)
		prefix_len = 2;
	else
		prefix_len = 0;
	if (width_precision[1] > num_len)
		width_precision[1] = width_precision[1] - num_len;
	else
		width_precision[1] = 0;
	width_precision[0] = width_precision[0] - (num_len + width_precision[1]
			+ prefix_len);
	combine_vars(comb, num, prefix_len, num_len);
	count += hexadecimal_conversion_bis_one(c, flags, width_precision, comb);
	return (count);
}
