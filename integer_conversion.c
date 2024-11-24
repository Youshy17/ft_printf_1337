#include "ft_printf.h"

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

void	integer_conversion(va_list args, int *flags, int *width_precision)
{
	int				temp;
	int				i;

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