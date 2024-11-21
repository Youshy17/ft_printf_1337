/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:37:59 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/21 12:39:26 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		ft_put_unsigned_nbr_fd((n + '0'), fd);
}
