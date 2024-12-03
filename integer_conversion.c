/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:42 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 18:10:13 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_padding(int nbr, int len, int *width_precision, int *flags)
{
	int	padding;

	if (nbr < 0)
	{
		if (width_precision[1] > len - 1)
			padding = width_precision[1] - (len - 1);
		else
			padding = 0;
	}
	else
	{
		if ((flags[4] || flags[5]) && width_precision[1] > len - 1)
			padding = width_precision[1] - (len - 1);
		else if (!flags[4] && !flags[5] && width_precision[1] > len)
			padding = width_precision[1] - len;
		else
			padding = 0;
	}
	return (padding);
}

int	integer_conversion_bis_one(int nbr, int len, int *width_precision,
	int *flags)
{
	int	count;
	int	padding;

	count = 0;
	padding = count_padding(nbr, len, width_precision, flags);
	if (flags[1] && !flags[2])
	{
		handle_sign(nbr, &count, flags);
		put_padding(width_precision[0] - len, '0', &count);
	}
	else
	{
		if (width_precision[1] == 0 && nbr == 0)
			put_padding(width_precision[0] - len - padding + 1, ' ',
				&count);
		else
			put_padding(width_precision[0] - len - padding, ' ', &count);
		handle_sign(nbr, &count, flags);
	}
	print_number(nbr, width_precision[1], &count);
	return (count);
}

int	integer_conversion(va_list args, int *flags, int *width_precision)
{
	int	nbr;
	int	len;
	int	padding;
	int	count;

	nbr = va_arg(args, int);
	count = 0;
	len = count_digits_dec(nbr);
	if (nbr >= 0 && (flags[4] || flags[5]))
		len++;
	padding = count_padding(nbr, len, width_precision, flags);
	if (flags[0])
	{
		handle_sign(nbr, &count, flags);
		print_number(nbr, width_precision[1], &count);
		if (width_precision[1] == 0 && nbr == 0)
			put_padding(width_precision[0] - len - padding + 1, ' ', &count);
		else
			put_padding(width_precision[0] - len - padding, ' ', &count);
	}
	else
		count += integer_conversion_bis_one(nbr, len, width_precision, flags);
	return (count);
}
