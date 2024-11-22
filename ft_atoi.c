/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:26:52 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/22 11:54:35 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	long	number;
	long	minus;

	number = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\n'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += (*str - 48);
		str ++;
	}
	return ((int)(number * minus));
}
