/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:50 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:39:36 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_len(int *flags)
{
	int	sign_len;

	if (flags[5] == 1)
		sign_len = 1;
	else
		sign_len = 0;
	return (sign_len);
}

int	num_len(void *ptr)
{
	int	num_len;

	if (!ptr)
		num_len = 5;
	else
		num_len = count_digits_address((unsigned long)ptr);
	return (num_len);
}

int	pointer_conversion_bis_one(int *flags, int *width_precision)
{
	int	count;

	count = 0;
	if (flags[0] == 1)
	{
		count = check_count(count, ft_putstr_fd("(nil)", 1));
		count = check_count(count, handle_padding(5, width_precision[0], ' '));
	}
	else
	{
		count = check_count(count, handle_padding(5, width_precision[0], ' '));
		count = check_count(count, ft_putstr_fd("(nil)", 1));
	}
	return (count);
}

int	pointer_conversion_bis_two(int *flags, int *width_precision,
	int total_len, void *ptr)
{
	int	count;

	count = 0;
	if (flags[2] == 1)
	{
		if (width_precision[1] > num_len(ptr))
			total_len = sign_len(flags) + 2 + width_precision[1];
		else
			total_len = sign_len(flags) + 2 + num_len(ptr);
	}
	if (flags[0] == 0)
	{
		if (flags[1] == 1 && flags[2] == 0)
			count = check_count(count,
					handle_padding(total_len, width_precision[0], '0'));
		else
			count = check_count(count,
					handle_padding(total_len, width_precision[0], ' '));
	}
	if (flags[5] == 1)
		count = check_count(count, ft_putchar_fd('+', 1));
	return (count);
}

int	pointer_conversion(va_list args, int *flags, int *width_precision)
{
	void	*ptr;
	int		total_len;
	int		count;

	ptr = va_arg(args, void *);
	count = 0;
	total_len = num_len(ptr) + sign_len(flags) + 2;
	if (!ptr)
		return (pointer_conversion_bis_one(flags, width_precision));
	count = check_count(count,
			pointer_conversion_bis_two(flags, width_precision, total_len, ptr));
	count = check_count(count,
			ft_putstr_fd("0x", 1));
	count = check_count(count,
			handle_padding(num_len(ptr), width_precision[1], '0'));
	count = check_count(count,
			print_address((unsigned long)ptr));
	if (flags[0] == 1)
		count = check_count(count,
				handle_padding(total_len, width_precision[0], ' '));
	return (count);
}
