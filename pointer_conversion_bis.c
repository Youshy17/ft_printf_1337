/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conversion_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:17:26 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/09 12:27:56 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_address(uintptr_t nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

int	print_address(uintptr_t num)
{
	if (num >= 16)
		print_address(num / 16);
	ft_putchar_fd("0123456789abcdef"[num % 16], 1);
	return (count_digits_address(num));
}

int	handle_padding(int total_len, int width, char pad_char)
{
	int	count;

	count = 0;
	while (total_len < width)
	{
		count = check_count(count, ft_putchar_fd(pad_char, 1));
		total_len++;
	}
	return (count);
}
