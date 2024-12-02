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

int	integer_conversion(va_list args, int *flags, int *width_precision)
{
	int	nbr;
	int	len;
	int	padding;
	int	count;
	int	is_negative;

	nbr = va_arg(args, int);
	count = 0;
	is_negative = nbr < 0;
	len = count_digits_dec(nbr);
	if (is_negative)
	{
		if (width_precision[1] > len - 1)
			padding = width_precision[1] - (len - 1);
		else
			padding = 0;
	}
	else
	{
		if (width_precision[1] > len)
			padding = width_precision[1] - len;
		else
			padding = 0;
	}
	if (flags[0])
	{
		handle_sign(nbr, &count);
		print_number(nbr, width_precision[1], &count);
		if (width_precision[1] == 0 && nbr == 0)
			put_padding(width_precision[0] - len - padding + 1, ' ', &count);
		else
			put_padding(width_precision[0] - len - padding, ' ', &count);
	}
	else
	{
		if (flags[1] && !flags[2])
		{
			handle_sign(nbr, &count);
			put_padding(width_precision[0] - len, '0', &count);
		}
		else
		{
			if (width_precision[1] == 0 && nbr == 0)
				put_padding(width_precision[0] - len - padding + 1, ' ',
					&count);
			else
				put_padding(width_precision[0] - len - padding, ' ', &count);
			handle_sign(nbr, &count);
		}
		print_number(nbr, width_precision[1], &count);
	}
	return (count);
}
