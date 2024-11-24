/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:55 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/24 10:50:38 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list args;
	int		flags[6];
	int		width_precision[2];


	va_start(args, format);
	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_memset(flags , 0, sizeof(flags)); // - 0 . # space +
			width_precision[0] = -1;
			width_precision[1] = -1;
			if (format[i] == '-' || format[i] == '0' || format[i] == '.' 
				|| format[i] == '#' || format[i] == ' ' || format[i] == '+' 
				|| (format[i] >= '0' && format[i] <= '9'))
				i += process_flag(&format[i], flags, width_precision);
			if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' 
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' 
				|| format[i] == 'x' || format[i] == 'X')
				process_conversions(format[i], args, flags, width_precision);
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}


/*
int main ()
{
	const char *format = "2.6c|\n";
	int flags[6]; // - 0 . # space +
	ft_memset(flags , 0, sizeof(flags));
	int width_precision[2];
	width_precision[0] = -1;
	width_precision[1] = -1;
	int ret = process_flag(format, flags, width_precision);
	printf("width is %d, precision is %d and i is %d\n", width_precision[0], width_precision[1], ret);
	for (int j = 0; j < 6 ; j++)
	{
		printf("%d", flags[j]);
	}
	printf("\n");
}

int main ()
{
	int a = 5;
	int *b = &a;
	ft_printf("This is a test |%+9.5d|\n",255);
	printf("This is a test |%+9.5d|\n",255);
}
*/

int main ()
{
	char *t = NULL;
	ft_printf("This is a test |%2.5s|\n",t);
	printf("This is a test |%2.5s|\n",t);
}
