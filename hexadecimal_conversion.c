#include "ft_printf.h"

void print_hex(unsigned int num , char c) {
    if (num >= 16) {
        print_hex(num / 16, c);
    }
	if (c == 'X')
    	ft_putchar_fd("0123456789ABCDEF"[num % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[num % 16], 1);
}
int	count_digits_hex(unsigned int nbr, int base)
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

void	hexadecimal_conversion(char c, va_list args, int *flags, int *width_precision)
{
	unsigned int	unsignedTemp;
	int				i;

	unsignedTemp = va_arg(args, int);
	i = count_digits_hex(unsignedTemp, 16);
	if (flags[3] == 1)
		i += 2;
	if (flags[3] == 1 && c == 'x')
		ft_putstr_fd("0x", 1);
	else if (flags[3] == 1 && c == 'X')
		ft_putstr_fd("0X", 1);
	if (flags[0] == 1)
	{
		if (flags[2] == 1 && width_precision[1] > i)
		{
			while (i++ < width_precision[1])
				ft_putchar_fd('0', 1);
			i = count_digits_hex(unsignedTemp, 16) + (width_precision[1] - count_digits_hex(unsignedTemp, 16));
			if (flags[3] == 1)
				i += 2;
		}
		print_hex(unsignedTemp, c);
		while (i++ < width_precision[0])
			ft_putchar_fd(' ', 1);
	}
	else if (flags[1] == 1 && flags[2] == 0 && width_precision[0] > i)
	{
		while (i++ < width_precision[0])
			ft_putchar_fd('0', 1);
		print_hex(unsignedTemp, c);
	}
	else
	{
		if (flags[2] == 1 && width_precision[1] > i)
		{
			i = count_digits_hex(unsignedTemp, 16) + (width_precision[1] - count_digits_hex(unsignedTemp, 16));
			if (flags[3] == 1)
				i += 2;
		}
		while (i++ < width_precision[0])
			ft_putchar_fd(' ', 1);
		i = count_digits_hex(unsignedTemp, 16);
		if (flags[3] == 1)
			i += 2;
		if (flags[2] == 1 && width_precision[1] > i)
		{
			while (i++ < width_precision[1])
				ft_putchar_fd('0', 1);
		}
		print_hex(unsignedTemp, c);
	}
}