/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:34 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:32:05 by yel-hamr         ###   ########.fr       */
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
		count = check_count(count, ft_putchar_fd('-', fd));
		nbr = (unsigned int)(n * (-1));
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		count = check_count(count, ft_putnbr_fd(nbr / 10, fd));
		count = check_count(count, ft_putchar_fd((nbr % 10 + '0'), fd));
	}
	else
		count = check_count(count, ft_putchar_fd((nbr + '0'), fd));
	return (count);
}
