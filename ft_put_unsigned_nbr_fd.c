/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:37:59 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/23 10:04:58 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = check_count(count, ft_put_unsigned_nbr_fd(n / 10, fd));
		count = check_count(count, ft_putchar_fd((n % 10 + '0'), fd));
	}
	else
		count = check_count(count, ft_putchar_fd((n + '0'), fd));
	return (count);
}
