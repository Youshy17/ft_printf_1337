/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:50 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 18:37:20 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_conversion_bis_three(int *flags, int *width_precision,
		int total_len, int num_len, void *ptr)
{
	int	count;

	count = 0;
	if (flags[0] == 0)
	{
		if (flags[1] == 1 && flags[2] == 0)
			count += handle_padding(total_len, width_precision[0], '0');
		else
			count += handle_padding(total_len, width_precision[0], ' ');
	}
	if (flags[5] == 1)
		count += ft_putchar_fd('+', 1);
	count += ft_putstr_fd("0x", 1);
	count += handle_padding(num_len, width_precision[1], '0');
	count += print_address((unsigned long)ptr);
	if (flags[0] == 1)
		count += handle_padding(total_len, width_precision[0], ' ');
	return (count);
}

int	pointer_conversion_bis_two(int *flags, int *width_precision, void *ptr,
		int num_len)
{
	int	count;
	int	total_len;
	int	sign_len;

	count = 0;
	if (flags[5] == 1)
		sign_len = 1;
	else
		sign_len = 0;
	total_len = num_len + sign_len + 2;
	if (flags[2] == 1)
	{
		if (width_precision[1] > num_len)
			total_len = sign_len + 2 + width_precision[1];
		else
			total_len = sign_len + 2 + num_len;
	}
	count += pointer_conversion_bis_three(flags, width_precision, total_len,
			num_len, ptr);
	return (count);
}

int	pointer_conversion_bis_one(int *flags, int *width_precision)
{
	int	count;

	count = 0;
	if (flags[0] == 1)
	{
		count += ft_putstr_fd("(nil)", 1);
		count += handle_padding(5, width_precision[0], ' ');
	}
	else
	{
		count += handle_padding(5, width_precision[0], ' ');
		count += ft_putstr_fd("(nil)", 1);
	}
	return (count);
}

int	pointer_conversion(va_list args, int *flags, int *width_precision)
{
	void	*ptr;
	int		num_len;
	int		count;

	ptr = va_arg(args, void *);
	count = 0;
	if (!ptr)
		num_len = 5;
	else
		num_len = count_digits_address((unsigned long)ptr);
	if (!ptr)
		return (pointer_conversion_bis_one(flags, width_precision));
	count += pointer_conversion_bis_two(flags, width_precision, ptr, num_len);
	return (count);
}
