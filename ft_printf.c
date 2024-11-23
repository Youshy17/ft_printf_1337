/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:40:55 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/23 13:50:53 by yel-hamr         ###   ########.fr       */
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
	const char *format = "%#X|\n";
	int flags[6]; // - 0 . # space +
	ft_memset(flags , 0, sizeof(flags));
	int width = 0;
	int precision = 0;
	int ret = flag_traitement(format, flags, 1, &width, &precision);
	printf("width is %d, precision is %d and i is %d\n", width, precision, ret);
	for (int j = 0; j < 6 ; j++)
	{
		printf("%d", flags[j]);
	}
	printf("\n");
}
*/
int main ()
{
	int a = 5;
	int *b = &a;
	ft_printf("This is a test |%+9.5d|\n",255);
	printf("This is a test |%+9.5d|\n",255);
}
