/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:54 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:07:55 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_conversions(char c, va_list args, int *flags, int *width_precision)
{
	if (c == 'c')
		character_conversion(args, flags, width_precision);
	else if (c == 's')
		string_conversion(args, flags, width_precision);
	else if (c == 'p')
		pointer_conversion(args, flags, width_precision);
	else if (c == 'd' || c == 'i')
		integer_conversion(args, flags, width_precision);
	else if (c == 'u')
		unsigned_conversion(args, flags, width_precision);
	else if (c == 'x' || c == 'X')
		hexadecimal_conversion(c, args, flags, width_precision);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}