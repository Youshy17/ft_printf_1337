/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:57 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:07:58 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int skip_numbers(const char *format)
{
    int i;

    i = 0;
    while (format[i] >= '0' && format[i] <= '9')
		i++;
    return (i - 1);
}

static int    first_process(const char *format, int *flags, int *width_precision, char c)
{
    int i;

    i = 0;
    if (c == '-')
		flags[0] = 1;
	else if (c == '0')
		flags[1] = 1;
	else if (c == '.')
	{
		flags[2] = 1;
		i++;
		width_precision[1] = ft_atoi(format + i);
		i += skip_numbers(format + 1);
	}
	else if (format[i] == '#')
		flags[3] = 1;
    return (i);
}

static int    second_process(const char *format, int *flags, int *width_precision, char c)
{
    int i;

    i = 0;
    if (c == ' ')
		flags[4] = 1;
	else if (c == '+')
		flags[5] = 1;
	else if (c>= '0' && c <= '9')
	{
		width_precision[0] = ft_atoi(format + i);
		i += skip_numbers(format + i);
	}
    return (i);
}

int	process_flag(const char *format, int *flags, int *width_precision)
{
    int i;

    i = 0;
	while(format[i])
	{
		if (format[i] == '-' || format[i] == '0' || format[i] == '.' || format[i] == '#')
            i += first_process(&format[i], flags, width_precision, format[i]);
		else if (format[i] == ' ' || format[i] == '+' || (format[i] >= '0' && format[i] <= '9'))
			i += second_process(&format[i], flags, width_precision, format[i]);
		else
			break;
		i++;
	}
	return (i);
}