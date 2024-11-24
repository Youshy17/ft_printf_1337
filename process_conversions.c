#include "ft_printf.h"

void	process_conversions(char c, va_list args, int *flags, int *width_precision)
{
	if (c == 'c')
		character_conversion(args, flags, width_precision);
	else if (c == 's')
		string_conversion(args, flags, width_precision);
	else if (c == 'p')
		pointer_conversion(args, flags, width_precision);
	else if (c == 'd' || c == 'i')
		integer_conversion(args, flags, width_precision);
	else if (c == 'u')
		unsigned_conversion(args, flags, width_precision);
	else if (c == 'x' || c == 'X')
		hexadecimal_conversion(c, args, flags, width_precision);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}