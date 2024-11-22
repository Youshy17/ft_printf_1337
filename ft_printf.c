/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:55 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/22 14:10:57 by yel-hamr         ###   ########.fr       */
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

int	flag_traitement(const char *format, int *flags, int i, int *width, int *precision)
{
	while(format[i])
	{
		if (format[i] == '-')
			flags[0] = 1;
		else if (format[i] == '0')
			flags[1] = 1;
		else if (format[i] == '.')
		{
			flags[2] = 1;
			i++;
			*precision = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
		}
		else if (format[i] == '#')
			flags[3] = 1;
		else if (format[i] == ' ')
			flags[4] = 1;
		else if (format[i] == '+')
			flags[5] = 1;
		else if (format[i] >= '0' && format[i] <= '9')
		{
			*width = ft_atoi(&format[i]);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			i--;
		}
		else
			break;
		i++;
	}
	return (i);
}

void	conversions_traitement(char c, va_list args, int *count, int *flags, int width, int precision)
{
	int	temp;
	int	i;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		if (flags[0] == 1)
		{
			i = 0;
			while (i++ < width - 1)
				ft_putchar_fd(' ', 1);
		}
	}
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
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
	else if (c == 'd' || c == 'i')
	{
		temp = va_arg(args, int);
		if (temp >= 0 && flags[5] == 1)
			ft_putchar_fd('+', 1);
		else if (temp >= 0 && flags[4] == 1)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(temp, 1);
	}
	else if (c == 'u')
		ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
	{
		if (flags[3] == 1)
			ft_putstr_fd("0x", 1);
		print_hex_lower(va_arg(args, int));
	}
	else if (c == 'X')
	{
		if (flags[3] == 1)
			ft_putstr_fd("0X", 1);
		print_hex_upper(va_arg(args, int));
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list args;
	int		flags[6] = {0};
	int		width;
	int		precision;


	va_start(args, format);
	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_memset(flags , 0, sizeof(flags)); // - 0 . # space +
			width = 0;
			precision = 0;
			if (format[i] == '-' || format[i] == '0' || format[i] == '.' 
				|| format[i] == '#' || format[i] == ' ' || format[i] == '+')
				i = flag_traitement(format, flags, i, &width, &precision);
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' 
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' 
				|| format[i] == 'x' || format[i] == 'X')
				conversions_traitement(format[i], args, &count, flags, width, precision);
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}


/*
int main ()
{
	const char *format = "%#X|\n";
	int flags[6]; // - 0 . # space +
	ft_memset(flags , 0, sizeof(flags));
	int width = 0;
	int precision = 0;
	int ret = flag_traitement(format, flags, 1, &width, &precision);
	printf("width is %d, precision is %d and i is %d\n", width, precision, ret);
	for (int j = 0; j < 6 ; j++)
	{
		printf("%d", flags[j]);
	}
	printf("\n");
}
*/
int main ()
{
	int a = 5;
	int *b = &a;
	ft_printf("This is a test |%-5c|\n", 'a');
	printf("This is a test |%-15p|\n", b);
}
