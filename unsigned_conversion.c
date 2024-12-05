/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:08:09 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:41:03 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	pad_width_unsigned(int width, char pad_char)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i++ < width)
		count = check_count(count, ft_putchar_fd(pad_char, 1));
	return (count);
}

int	unsigned_conversion_bis(unsigned int num, int *flags, int *width_precision)
{
	int				num_len;

	num_len = count_digits_unsigned(num);
	if (flags[2] == 1 && width_precision[1] == 0 && num == 0)
		num_len = 0;
	if (width_precision[1] > num_len)
		width_precision[1] = width_precision[1] - num_len;
	else
		width_precision[1] = 0;
	width_precision[0] = width_precision[0] - (num_len + width_precision[1]);
	return (num_len);
}

int	unsigned_conversion(va_list args, int *flags, int *width_precision)
{
	unsigned int	num;
	int				num_len;
	int				count;

	num = va_arg(args, unsigned int);
	num_len = unsigned_conversion_bis(num, flags, width_precision);
	count = 0;
	if (flags[0] == 1)
	{
		count = check_count(count, pad_width_unsigned(width_precision[1], '0'));
		if (num_len > 0)
			count = check_count(count, ft_put_unsigned_nbr_fd(num, 1));
		count = check_count(count, pad_width_unsigned(width_precision[0], ' '));
	}
	else
	{
		if (flags[1] == 1 && flags[2] == 0)
			count = check_count(count, pad_width_unsigned(width_precision[0], '0'));
		else
			count = check_count(count, pad_width_unsigned(width_precision[0], ' '));
		count = check_count(count, pad_width_unsigned(width_precision[1], '0'));
		if (num_len > 0)
			count = check_count(count, ft_put_unsigned_nbr_fd(num, 1));
	}
	return (count);
}
