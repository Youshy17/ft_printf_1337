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

void	unsigned_conversion(va_list args, int *flags, int *width_precision)
{
	unsigned int	unsignedTemp;
	int				i;
	
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