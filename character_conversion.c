/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:07:22 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/26 12:07:25 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character_conversion(va_list args, int *flags, int *width_precision)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (flags[0] == 1)
	{
		count += ft_putchar_fd(va_arg(args, int), 1);
		while (i < width_precision[0] - 1)
		{
			count += ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else
	{
		while (i < width_precision[0] - 1)
		{
			count += ft_putchar_fd(' ', 1);
			i++;
		}
		count += ft_putchar_fd(va_arg(args, int), 1);
	}
}
