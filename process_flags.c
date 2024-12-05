/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:57 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:29:05 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	skip_numbers(const char *format)
{
	int	i;

	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i);
}

static void	first_process(int *flags, char c)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0')
		flags[1] = 1;
	else if (c == '#')
		flags[3] = 1;
	else if (c == ' ')
		flags[4] = 1;
	else if (c == '+')
		flags[5] = 1;
}

static int	second_process(const char *format, int *width_precision)
{
	int	i;

	i = 0;
	width_precision[0] = ft_atoi(format);
	i += skip_numbers(format);
	return (i);
}

static int	third_process(const char *format, int *flags, int *width_precision)
{
	int	i;

	i = 0;
	flags[2] = 1;
	i++;
	width_precision[1] = ft_atoi(format + i);
	i += skip_numbers(format + i);
	return (i);
}

int	process_flag(const char *format, int *flags, int *width_precision)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0' || format[i] == '#'
		|| format[i] == ' ' || format[i] == '+')
	{
		first_process(flags, format[i]);
		i++;
	}
	if ((format[i] >= '0' && format[i] <= '9'))
		i += second_process(&format[i], width_precision);
	if (format[i] == '.')
		i += third_process(&format[i], flags, width_precision);
	return (i);
}
