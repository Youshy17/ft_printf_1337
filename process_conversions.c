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

void	process_conversions(char c, va_list args, int *flags, int *width_precision)
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
			while (i++ < width_precision[0] - 1)
				ft_putchar_fd(' ', 1);
		}
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL && (width_precision[1] == -1 || width_precision[1] >= 6))
			str = "(null)";
		else if (str == NULL)
			str = "";
		if (flags[0] == 1 && width_precision[0] > (int)ft_strlen(str))
		{
			if (flags[2] == 0 || (flags[2] == 1 && width_precision[1] >= (int)ft_strlen(str)))
			{
				ft_putstr_fd(str, 1);
				i = (int)ft_strlen(str);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
			}
			else if (flags[2] == 1 && width_precision[1] < (int)ft_strlen(str))
			{
				i = 0;
				while (str && i++ < width_precision[1])
					ft_putchar_fd(str[i - 1], 1);
				width_precision[0] += (ft_strlen(str) - width_precision[1]);
				i = (int)ft_strlen(str);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
			}
		}
		else if (flags[0] == 0 && width_precision[0] > (int)ft_strlen(str))
		{
			if (flags[2] == 0 || (flags[2] == 1 && width_precision[1] >= (int)ft_strlen(str)))
			{
				i = (int)ft_strlen(str);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
				ft_putstr_fd(str, 1);
			}
			else if (flags[2] == 1 && width_precision[1] < (int)ft_strlen(str))
			{
				width_precision[0] += (ft_strlen(str) - width_precision[1]);
				i = (int)ft_strlen(str);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
				i = 0;
				while (str && i++ < width_precision[1])
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
			if (flags[0] == 1 && width_precision[0] > i)
			{
				ft_putstr_fd("0x", 1);
            	print_address(longTemp);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
			}
			else if (flags[1] == 1 && width_precision[0] > i)
			{
				ft_putstr_fd("0x", 1);
				while (i++ < width_precision[0])
					ft_putchar_fd('0', 1);
            	print_address(longTemp);
			}
			else if (width_precision[0] > i)
			{
				while (i++ < width_precision[0])
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
			if (flags[0] == 1 && width_precision[0] > i)
			{
				ft_putstr_fd("(nil)", 1);
				while (i++ < width_precision[0])
					ft_putchar_fd(' ', 1);
			}
			else if (width_precision[0] > i)
			{
				while (i++ < width_precision[0])
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
		if (flags[4] == 1 || flags[5] == 1)
			i++;
		if (flags[0] == 1)
		{
			if (flags[2] == 1 && width_precision[1] > i)
			{
				if (temp >= 0 && flags[5] == 1)
					ft_putchar_fd('+', 1);
				else if (temp >= 0 && flags[4] == 1)
					ft_putchar_fd(' ', 1);
				while (i++ < width_precision[1])
					ft_putchar_fd('0', 1);
				i = count_digits_dec(temp) + (width_precision[1] - count_digits_dec(temp));
				if (flags[4] == 1 || flags[5] == 1)
					i++;
			}
			ft_putnbr_fd(temp, 1);
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
		}
		else if (flags[1] == 1 && flags[2] == 0 && width_precision[0] > i)
		{
			if (temp >= 0 && flags[5] == 1)
				ft_putchar_fd('+', 1);
			else if (temp >= 0 && flags[4] == 1)
				ft_putchar_fd(' ', 1);
			while (i++ < width_precision[0])
				ft_putchar_fd('0', 1);
			ft_putnbr_fd(temp, 1);
		}
		else
		{
			if (flags[2] == 1 && width_precision[1] > i)
			{
				i = count_digits_dec(temp) + (width_precision[1] - count_digits_dec(temp));
				if (flags[4] == 1 || flags[5] == 1)
					i++;
			}
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
			i = count_digits_dec(temp);
			if (flags[4] == 1 || flags[5] == 1)
				i++;

			if (temp >= 0 && flags[5] == 1)
				ft_putchar_fd('+', 1);
			else if (temp >= 0 && flags[4] == 1)
				ft_putchar_fd(' ', 1);
			
			if (flags[2] == 1 && width_precision[1] > i)
			{
				while (i++ < width_precision[1])
					ft_putchar_fd('0', 1);
			}
			ft_putnbr_fd(temp, 1);
		}
	}
	else if (c == 'u')
	{
		unsignedTemp = va_arg(args, unsigned int);
		i = count_digits_unsigned(unsignedTemp, 10);
		if (flags[0] == 1 && width_precision[0] > i)
		{
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
		}
		else if (flags[1] == 1 && width_precision[0] > i)
		{
			while (i++ < width_precision[0])
				ft_putchar_fd('0', 1);
			ft_put_unsigned_nbr_fd(unsignedTemp, 1);
		}
		else if (width_precision[0] > i)
		{
			while (i++ < width_precision[0])
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
				i = count_digits_unsigned(unsignedTemp, 16) + (width_precision[1] - count_digits_unsigned(unsignedTemp, 16));
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
				i = count_digits_unsigned(unsignedTemp, 16) + (width_precision[1] - count_digits_unsigned(unsignedTemp, 16));
				if (flags[3] == 1)
					i += 2;
			}
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
			i = count_digits_unsigned(unsignedTemp, 16);
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
	else if (c == '%')
		ft_putchar_fd('%', 1);
}