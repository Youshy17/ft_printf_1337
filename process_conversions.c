/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:54 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/06 12:37:29 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_conversions(char c, va_list args, int *flags, int *width_precision)
{
	int	count;

	if (c == 'c')
		count = character_conversion(args, flags, width_precision);
	else if (c == 's')
		count = string_conversion(args, flags, width_precision);
	else if (c == 'p')
		count = pointer_conversion(args, flags, width_precision);
	else if (c == 'd' || c == 'i')
		count = integer_conversion(args, flags, width_precision);
	else if (c == 'u')
		count = unsigned_conversion(args, flags, width_precision);
	else if (c == 'x' || c == 'X')
		count = hexadecimal_conversion(c, args, flags, width_precision);
	else
		count = 0;
	return (count);
}
