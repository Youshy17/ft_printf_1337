/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:42 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/28 11:31:26 by yel-hamr         ###   ########.fr       */
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

void	handle_sign(int nbr, int *count)
{
	if (nbr < 0)
		*count += ft_putchar_fd('-', 1);
}

void	print_padding(int len, char c, int *count)
{
	while (len > 0)
	{
		*count += ft_putchar_fd(c, 1);
		len--;
	}
}

void	print_number(int nbr, int precision, int *count)
{
	int	padding;

	if (nbr == -2147483648)
	{
		padding = precision - count_digits_dec(nbr) - 1;
		print_padding(padding, '0', count);
		if (nbr == 0 && precision == 0)
			return ;
		*count += ft_putstr_fd("2147483648", 1);
		return ;
	}
	if (nbr < 0)
		nbr = -nbr;
	padding = precision - count_digits_dec(nbr);
	print_padding(padding, '0', count);
	if (nbr == 0 && precision == 0)
		return ;
	
	*count += ft_putnbr_fd(nbr, 1);
}

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
	if (width_precision[1] > len - (is_negative ? 1 : 0))
		padding = width_precision[1] - (len - (is_negative ? 1 : 0));
	else
		padding = 0;

	if (flags[0]) // Left-align
	{
		handle_sign(nbr, &count);
		print_number(nbr, width_precision[1], &count);
		print_padding(width_precision[0] - len - padding, ' ', &count);
	}
	else
	{
		if (flags[1] && !flags[2])
		{
			handle_sign(nbr, &count);
			print_padding(width_precision[0] - len, '0', &count);
		}
		else
		{
			if (width_precision[1] == 0 && nbr == 0)
				print_padding(width_precision[0] - len - padding + 1, ' ', &count);
			else
				print_padding(width_precision[0] - len - padding, ' ', &count);
			handle_sign(nbr, &count);
		}
		print_number(nbr, width_precision[1], &count);
	}
	return (count);
}
