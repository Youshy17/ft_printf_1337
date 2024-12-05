/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:16:31 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:29:23 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conversion_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0' || format[i] == '#'
		|| format[i] == ' ' || format[i] == '+')
		i++;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		return (1);
	else
		return (0);
}
