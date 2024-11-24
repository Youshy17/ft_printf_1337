#include "ft_printf.h"

char	*set_string(va_list args, int *flags, int *width_precision)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL && (flags[2] == 0 || width_precision[1] >= 6))
		str = "(null)";
	else if (str == NULL)
		str = "";
	return (str);
}

void	string_conversion(va_list args, int *flags, int *width_precision)
{
	int		i;
	char	*str;
	int		strlen;

	str = set_string(args, flags, width_precision);

	if (width_precision[1] != -1 && width_precision[1] < ft_strlen(str))
		strlen = width_precision[1];
	else
		strlen = ft_strlen(str);

	if (flags[0] == 1)
	{
		if (flags[2] == 0)
		{
			ft_putstr_fd(str, 1);
			i = strlen;
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
		}
		else if (flags[2] == 1)
		{
			i = 0;
			while (str && i++ < strlen)
				ft_putchar_fd(str[i - 1], 1);
			i = strlen;
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		if (flags[2] == 0)
		{
			i = strlen;
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(str, 1);
		}
		else if (flags[2] == 1)
		{
			i = strlen;
			while (i++ < width_precision[0])
				ft_putchar_fd(' ', 1);
			i = 0;
			while (str && i++ < width_precision[1])
				ft_putchar_fd(str[i - 1], 1);
		}
	}
}


/*
// not working!
int main ()
{
	char *t = NULL;
	ft_printf("This is a test |%2.5s|\n",t);
	printf("This is a test |%2.5s|\n",t);
}


*/