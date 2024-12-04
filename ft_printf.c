/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:55 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/04 15:29:25 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, va_list args, int *flags,
		int *width_precision)
{
	int	temp;

	ft_memset(flags, 0, sizeof(flags));
	width_precision[0] = -1;
	width_precision[1] = -1;
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		temp = process_conversions(*format, args, flags, width_precision);
	else if (*format == '%')
		temp = ft_putchar_fd('%', 1);
	else if (*format != '\0')
	{
		temp = ft_putchar_fd('%', 1);
		temp += ft_putchar_fd(*format, 1);
	}
	else
		return (-1);
	return (temp);
}

int	process_format(const char *format, va_list args, int *flags,
		int *width_precision)
{
	int	i;
	int	temp;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			temp = check_format(&format[i], args, flags, width_precision);
		}
		else
			temp = ft_putchar_fd(format[i], 1);
		i++;
		if (temp != -1)
			count += temp;
		else
			return (temp);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		flags[6];
	int		width_precision[2];
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = process_format(format, args, flags, width_precision);
	va_end(args);
	return (count);
}

/*
int main ()
{
	const char	*format = "2.6c|\n";
	int			width_precision[2];
	int			ret;

	int flags[6]; // - 0 . # space +
	ft_memset(flags , 0, sizeof(flags));
	width_precision[0] = -1;
	width_precision[1] = -1;
	ret = process_flag(format, flags, width_precision);
	printf("width is %d, precision is %d and i is %d\n", width_precision[0],
		width_precision[1], ret);
	for (int j = 0; j < 6 ; j++)
	{
		printf("%d", flags[j]);
	}
	printf("\n");
}

int main ()
{
	int	a;
	int	*b;

	a = 5;
	b = &a;
	ft_printf("This is a test |%+9.5d|\n",255);
	printf("This is a test |%+9.5d|\n",255);
}


int main ()
{
	int	o;
	int	*t;

	o = 5;
	t = &o;
	ft_printf("This is a test |%-40.18p|\n",t);
	printf("This is a test |%-40.18p|\n",t);
}


int main ()
{
	int	a;
	int	*b;

	a = 5;
	b = &a;
	ft_printf("This is a test |%+9.5u|\n",-515151515);
	printf("This is a test |%+9.5u|\n",-515151515);
}
*/