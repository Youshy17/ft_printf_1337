/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:21:34 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:28:52 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_flags(const char *format, int *flags, int *width_precision)
{
	int	i;

	i = 0;
	ft_memset(flags, 0, sizeof(flags));
	width_precision[0] = -1;
	width_precision[1] = -1;
	if (check_conversion_format(format) == 0)
		return (0);
	if (format[i] == '-' || format[i] == '0' || format[i] == '.'
		|| format[i] == '#' || format[i] == ' ' || format[i] == '+'
		|| (format[i] >= '0' && format[i] <= '9'))
		i += process_flag(&format[i], flags, width_precision);
	return (i);
}

int	read_conversions(const char *format, va_list args, int *flags,
		int *width_precision)
{
	int	count;

	count = 0;
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		count = check_count(count, process_conversions(*format, args, flags,
					width_precision));
	else if (*format == '%')
		count = check_count(count, ft_putchar_fd('%', 1));
	else if (*format != '\0')
	{
		count = check_count(count, ft_putchar_fd('%', 1));
		count = check_count(count, ft_putchar_fd(*format, 1));
	}
	else
		return (-1);
	return (count);
}

int	process_format(const char *format, va_list args, int *flags,
		int *width_precision)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += read_flags(&format[i], flags, width_precision);
			count = check_count(count, read_conversions(&format[i], args, flags,
						width_precision));
		}
		else
			count = check_count(count, ft_putchar_fd(format[i], 1));
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		flags[6];
	int		width_precision[2];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	ft_memset(flags, 0, sizeof(flags));
	width_precision[0] = -1;
	width_precision[1] = -1;
	count = process_format(format, args, flags, width_precision);
	va_end(args);
	return (count);
}
