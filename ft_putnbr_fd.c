/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:34 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/21 11:21:45 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr = (unsigned int)(n * (-1));
	}
	else
		nbr = (unsigned int) n;
	if (nbr >= 10)
	{
		count += ft_putnbr_fd(nbr / 10, fd);
		count += ft_putchar_fd((nbr % 10 + '0'), fd);
	}
	else
		count += ft_putchar_fd((nbr + '0'), fd);
	return (count);
}
