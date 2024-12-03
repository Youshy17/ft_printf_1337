/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:06:47 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 18:11:40 by yel-hamr         ###   ########.fr       */
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

void	handle_sign(int nbr, int *count, int *flags)
{
	if (nbr < 0)
		*count += ft_putchar_fd('-', 1);
	else if (flags[5])
		*count += ft_putchar_fd('+', 1);
	else if (flags[4])
		*count += ft_putchar_fd(' ', 1);
}

void	put_padding(int len, char c, int *count)
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
		put_padding(padding, '0', count);
		if (nbr == 0 && precision == 0)
			return ;
		*count += ft_putstr_fd("2147483648", 1);
		return ;
	}
	if (nbr < 0)
		nbr = -nbr;
	padding = precision - count_digits_dec(nbr);
	put_padding(padding, '0', count);
	if (nbr == 0 && precision == 0)
		return ;
	*count += ft_putnbr_fd(nbr, 1);
}
