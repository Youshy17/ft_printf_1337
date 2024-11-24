#include "ft_printf.h"

void	character_conversion(va_list args, int *flags, int *width_precision)
{
	int				i;

	i = 0;
	if (flags[0] == 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		while (i++ < width_precision[0] - 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (i++ < width_precision[0] - 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(va_arg(args, int), 1);
	}
}