/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:07 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/21 13:17:13 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_hex(uintptr_t num) {
    if (num >= 16) {
        print_hex(num / 16);
    }
    ft_putchar_fd("0123456789abcdef"[num % 16], 1);
}

void print_hex_lower(unsigned int num) {
    if (num >= 16) {
        print_hex_lower(num / 16);
    }
    ft_putchar_fd("0123456789abcdef"[num % 16], 1);
}

void print_hex_upper(unsigned int num) {
    if (num >= 16) {
        print_hex_upper(num / 16);
    }
    ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	va_list args;
	va_start(args, str);

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'p')
			{
				void *ptr = va_arg(args, void *);
                if (ptr)
				{
                    ft_putstr_fd("0x", 1);
                    print_hex((uintptr_t)ptr);
                }
				else
                    ft_putstr_fd("(nil)", 1);
			}
			else if (str[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 'u')
				ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
			else if (str[i] == 'x')
				print_hex_lower(va_arg(args, int));
			else if (str[i] == 'X')
				print_hex_upper(va_arg(args, int));
			else if (str[i] == '%')
				ft_putchar_fd('%', 1);
			i++;
			count++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

int main ()
{
	int a = 5;
	int *b;
	ft_printf("Hello world %d %s %x\n", 50, "test", 255);
	printf("Hello world %d %s %x\n", 50, "test", 255);
	//printf("%d", count);
}