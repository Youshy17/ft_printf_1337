/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:08:04 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 17:06:05 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	string_conversion_bis(int *flags, int *width_precision, char *str,
		int strlen)
{
	int	count;
	int	i;

	count = 0;
	if (flags[0] == 1)
	{
		i = 0;
		while (i < strlen)
			count += ft_putchar_fd(str[i++], 1);
		while (i++ < width_precision[0])
			count += ft_putchar_fd(' ', 1);
		return (count);
	}
	return (count);
}

int	string_conversion(va_list args, int *flags, int *width_precision)
{
	char	*str;
	int		strlen;
	int		i;
	int		count;

	str = set_string(args, flags, width_precision);
	strlen = ft_strlen(str);
	count = 0;
	if (width_precision[1] != -1 && width_precision[1] < strlen)
		strlen = width_precision[1];
	count += string_conversion_bis(flags, width_precision, str, strlen);
	i = strlen;
	while (i++ < width_precision[0])
		count += ft_putchar_fd(' ', 1);
	i = 0;
	while (i < strlen)
		count += ft_putchar_fd(str[i++], 1);
	return (count);
}

/*
// not working!
int main ()
{
	char	*t;

	t = NULL;
	ft_printf("This is a test |%2.5s|\n",t);
	printf("This is a test |%2.5s|\n",t);
}


*/