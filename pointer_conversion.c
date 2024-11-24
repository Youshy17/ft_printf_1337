#include "ft_printf.h"

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

void	pointer_conversion(va_list args, int *flags, int *width_precision)
{
	void			*ptr;
	int				i;
	unsigned long	longTemp;
	
	ptr = va_arg(args, void *);
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

/*
int main ()
{
	int o = 5;
	int *t = &o;
	ft_printf("This is a test |%015p|\n",t);
	printf("This is a test |%015p|\n",t);
}
*/