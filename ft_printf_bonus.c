/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:21:34 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:22:57 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list args;
	int		flags[6];
	int		width_precision[2];


	va_start(args, format);
	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_memset(flags , 0, sizeof(flags));
			width_precision[0] = -1;
			width_precision[1] = -1;
			if (format[i] == '-' || format[i] == '0' || format[i] == '.' 
				|| format[i] == '#' || format[i] == ' ' || format[i] == '+' 
				|| (format[i] >= '0' && format[i] <= '9'))
				i += process_flag(&format[i], flags, width_precision);
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' 
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' 
				|| format[i] == 'x' || format[i] == 'X')
				count += process_conversions(format[i], args, flags, width_precision);
			else if (format[i] == '%')
				count += ft_putchar_fd('%', 1);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}