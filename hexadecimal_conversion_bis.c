/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_conversion_bis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:54:21 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:33:06 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int num, char c)
{
	int	count;

	count = 0;
	if (num >= 16)
		count = check_count(count, print_hex(num / 16, c));
	if (c == 'X')
		count = check_count(count, ft_putchar_fd("0123456789ABCDEF"[num % 16], 1));
	else
		count = check_count(count, ft_putchar_fd("0123456789abcdef"[num % 16], 1));
	return (count);
}

int	count_digits_hex(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}
