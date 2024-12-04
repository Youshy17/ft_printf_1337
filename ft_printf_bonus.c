/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:21:34 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/04 15:30:00 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(int *flags, int *width_precision, const char *format)
{
	int	i;

	i = 0;
	ft_memset(flags, 0, sizeof(flags));
	width_precision[0] = -1;
	width_precision[1] = -1;
	if (format[i] == '-' || format[i] == '0' || format[i] == '.'
		|| format[i] == '#' || format[i] == ' ' || format[i] == '+'
		|| (format[i] >= '0' && format[i] <= '9'))
		i += process_flag(&format[i], flags, width_precision);
	return (i);
}

int	check_format(const char *format, va_list args, int *flags,
		int *width_precision)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X')
		count += process_conversions(format[i], args, flags, width_precision);
	else if (format[i] == '%')
		count += ft_putchar_fd('%', 1);
	else if (format[i] != '\0')
	{
		count = ft_putchar_fd('%', 1);
		count += ft_putchar_fd(format[i], 1);
	}
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;
	int		flags[6];
	int		width_precision[2];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += check_flags(flags, width_precision, &format[i]);
			count += check_format(format, args, flags, width_precision);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
