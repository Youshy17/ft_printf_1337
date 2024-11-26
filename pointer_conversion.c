/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:50 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:07:51 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_address(unsigned long nbr)
{
	int	count = 0;

	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	print_address(unsigned long num)
{
	if (num >= 16)
		print_address(num / 16);
	ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	return (count_digits_address(num));
}

void	handle_padding(int total_len, int width, char pad_char)
{
	while (total_len < width)
	{
		ft_putchar_fd(pad_char, 1);
		total_len++;
	}
}

void	pointer_conversion(va_list args, int *flags, int *width_precision)
{
	void			*ptr;
	unsigned long	addr;
	int				num_len;
	int				sign_len;
	int				prefix_len;
	int				total_len;

	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	if (!ptr)
		num_len = 5;
	else
		num_len = count_digits_address(addr);
	if (flags[5] == 1)
		sign_len = 1;
	else
		sign_len = 0;
	prefix_len = 2;
	total_len = num_len + sign_len + prefix_len;

	if (!ptr)
	{
		if (flags[0] == 1)
		{
			ft_putstr_fd("(nil)", 1);
			handle_padding(5, width_precision[0], ' ');
		}
		else
		{
			handle_padding(5, width_precision[0], ' ');
			ft_putstr_fd("(nil)", 1);
		}
		return;
	}

	if (flags[2] == 1)
	{
		if (width_precision[1] > num_len)
			total_len = sign_len + prefix_len + width_precision[1];
		else
			total_len = sign_len + prefix_len + num_len;
	}

	if (flags[0] == 0)
	{
		if (flags[1] == 1 && flags[2] == 0)
			handle_padding(total_len, width_precision[0], '0');
		else
			handle_padding(total_len, width_precision[0], ' ');
	}

	if (flags[5] == 1)
		ft_putchar_fd('+', 1);
	ft_putstr_fd("0x", 1);
	handle_padding(num_len, width_precision[1], '0');
	print_address(addr);

	if (flags[0] == 1)
		handle_padding(total_len, width_precision[0], ' ');
}
