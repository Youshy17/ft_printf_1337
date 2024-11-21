#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list args;
	va_start(args, str);

	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(args, char), 1);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), 1);
			else if (str[i] == 'p')
				ft_putstr(va_arg(args, char *), 1);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), 1);
			else if (str[i] == 'i')
				ft_putnbr(va_arg(args, int), 1);
			else if (str[i] == 'u')
				ft_putnbr(va_arg(args, int), 1);
			else if (str[i] == 'x')
				ft_putnbr(va_arg(args, int), 1);
			else if (str[i] == 'X')
				ft_putnbr(va_arg(args, int), 1);
			else if (str[i] == '%')
				ft_putchar('%', 1);
			i++;
		}
		else
			if (str[i++] == 'c')
				ft_putchar(va_arg(args, char), 1);
	}
	va_end(args);
}