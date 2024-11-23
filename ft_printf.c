/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:55 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/23 11:57:13 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_unsigned(unsigned int nbr, int base)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		count++;
		if (base == 16)
			nbr /= 16;
		else
			nbr /= 10;
	}
	return (count);
}

int	count_digits_dec(int nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count = 1;
	else
		count = 0;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	count_digits_address(unsigned long nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 16;
	}
	return (count);
}

void print_address(unsigned long num) {
    if (num >= 16) {
        print_address(num / 16);
    }
    ft_putchar_fd("0123456789abcdef"[num % 16], 1);
}

void print_hex(unsigned int num , char c) {
    if (num >= 16) {
        print_hex(num / 16, c);
    }
	if (c == 'X')
    	ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
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
	int				temp;
	unsigned int	unsignedTemp;
	unsigned long	longTemp;
	int				i;
	char			*str;

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
	{
		str = va_arg(args, char *);
		if (str == NULL && (precision == -1 || precision >= 6))
			str = "(null)";
		else if (str == NULL)
			str = "";
		if (flags[0] == 1 && width > (int)ft_strlen(str))
		{
			if (flags[2] == 0 || (flags[2] == 1 && precision >= (int)ft_strlen(str)))
			{
				ft_putstr_fd(str, 1);
				i = (int)ft_strlen(str);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
			}
			else if (flags[2] == 1 && precision < (int)ft_strlen(str))
			{
				i = 0;
				while (str && i++ < precision)
					ft_putchar_fd(str[i - 1], 1);
				width += (ft_strlen(str) - precision);
				i = (int)ft_strlen(str);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
			}
		}
		else if (flags[0] == 0 && width > (int)ft_strlen(str))
		{
			if (flags[2] == 0 || (flags[2] == 1 && precision >= (int)ft_strlen(str)))
			{
				i = (int)ft_strlen(str);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd(str, 1);
			}
			else if (flags[2] == 1 && precision < (int)ft_strlen(str))
			{
				width += (ft_strlen(str) - precision);
				i = (int)ft_strlen(str);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
				i = 0;
				while (str && i++ < precision)
					ft_putchar_fd(str[i - 1], 1);
			}
		}
		else
			ft_putstr_fd(str, 1);
	}
	else if (c == 'p')
	{
		void *ptr = va_arg(args, void *);
        if (ptr)
		{
			longTemp = (unsigned long)ptr;
			i = count_digits_address(longTemp) + 2;
			if (flags[0] == 1 && width > i)
			{
				ft_putstr_fd("0x", 1);
            	print_address(longTemp);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
			}
			else if (flags[1] == 1 && width > i)
			{
				ft_putstr_fd("0x", 1);
				while (i++ < width)
					ft_putchar_fd('0', 1);
            	print_address(longTemp);
			}
			else if (width > i)
			{
				while (i++ < width)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd("0x", 1);
            	print_address(longTemp);
			}
			else
			{
    	    	ft_putstr_fd("0x", 1);
            	print_address(longTemp);
			}
        }
		else
		{
			i = 5;
			if (flags[0] == 1 && width > i)
			{
				ft_putstr_fd("(nil)", 1);
				while (i++ < width)
					ft_putchar_fd(' ', 1);
			}
			else if (width > i)
			{
				while (i++ < width)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd("(nil)", 1);
			}
			else
    	    	ft_putstr_fd("(nil)", 1);
		}
	}
	else if (c == 'd' || c == 'i')
	{
		temp = va_arg(args, int);
		i = count_digits_dec(temp);
		if (temp >= 0 && flags[5] == 1)
		{
			ft_putchar_fd('+', 1);
			i++;
		}
		else if (temp >= 0 && flags[4] == 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (flags[0] == 1 && width > i)
		{
			ft_putnbr_fd(temp, 1);
			while (i++ < width)
				ft_putchar_fd(' ', 1);
		}
		else if (flags[1] == 1 && width > i)
		{
			while (i++ < width)
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(temp, 1);
		}
		else if (width > i)
		{
			while (i++ < width)
				ft_putchar_fd(' ', 1);
			ft_putnbr_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
	else if (c == 'u')
	{
		unsignedTemp = va_arg(args, unsigned int);
		i = count_digits_unsigned(unsignedTemp, 10);
		if (flags[0] == 1 && width > i)
		{
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
			while (i++ < width)
				ft_putchar_fd(' ', 1);
		}
		else if (flags[1] == 1 && width > i)
		{
			while (i++ < width)
				ft_putchar_fd('0', 1);
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
		}
		else if (width > i)
		{
			while (i++ < width)
				ft_putchar_fd(' ', 1);
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
		}
		else
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
	}
	else if (c == 'x' || c == 'X')
	{
		unsignedTemp = va_arg(args, int);
		i = count_digits_unsigned(unsignedTemp, 16);
		if (flags[3] == 1 && c == 'x')
			ft_putstr_fd("0x", 1);
		else if (flags[3] == 1 && c == 'X')
			ft_putstr_fd("0X", 1);
		if (flags[0] == 1 && width > i)
		{
			print_hex(unsignedTemp, c);
			while (i++ < width)
				ft_putchar_fd(' ', 1);
		}
		else if (flags[1] == 1 && width > i)
		{
			while (i++ < width)
				ft_putchar_fd('0', 1);
			print_hex(unsignedTemp, c);
		}
		else if (width > i)
		{
			while (i++ < width)
				ft_putchar_fd(' ', 1);
			print_hex(unsignedTemp, c);
		}
		else
			print_hex(unsignedTemp, c);
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
			width = -1;
			precision = -1;
			if (format[i] == '-' || format[i] == '0' || format[i] == '.' 
				|| format[i] == '#' || format[i] == ' ' || format[i] == '+' 
				|| (format[i] >= '0' && format[i] <= '9'))
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
	ft_printf("This is a test |%7.6s|\n","test");
	printf("This is a test |%7.6s|\n","test");
}
