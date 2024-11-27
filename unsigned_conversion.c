/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:08:09 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:08:10 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_unsigned(unsigned int nbr)
{
	int	count = 0;

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
		count += ft_putchar_fd(pad_char, 1);
	return (count);
}

int	unsigned_conversion(va_list args, int *flags, int *width_precision)
{
	unsigned int	num;
	int				num_len;
	int				padding_len;
	int				count;

	num = va_arg(args, unsigned int);
	num_len = count_digits_unsigned(num);
	count = 0;

	if (width_precision[1] > num_len)
		padding_len = width_precision[1] - num_len;
	else
		padding_len = 0;

	if (flags[0] == 1)
	{
		count += pad_width_unsigned(padding_len, '0');
		count += ft_put_unsigned_nbr_fd(num, 1);
		count += pad_width_unsigned(width_precision[0] - num_len - padding_len, ' ');
	}
	else
	{
		if (flags[1] == 1)
			count += pad_width_unsigned(width_precision[0] - num_len - padding_len, '0');
		else
			count += pad_width_unsigned(width_precision[0] - num_len - padding_len, ' ');

		count += pad_width_unsigned(padding_len, '0');
		count += ft_put_unsigned_nbr_fd(num, 1);
	}
	return (count);
}
 