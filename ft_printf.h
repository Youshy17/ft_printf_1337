/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:17 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/02 18:18:14 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		process_flag(const char *format, int *flags, int *width_precision);
int		process_conversions(char c, va_list args, int *flags,
			int *width_precision);
int		character_conversion(va_list args, int *flags, int *width_precision);
int		string_conversion(va_list args, int *flags, int *width_precision);
int		pointer_conversion(va_list args, int *flags, int *width_precision);
int		count_digits_address(unsigned long nbr);
int		print_address(unsigned long num);
int		handle_padding(int total_len, int width, char pad_char);
int		integer_conversion(va_list args, int *flags, int *width_precision);
int		count_digits_dec(int nbr);
void	handle_sign(int nbr, int *count, int *flags);
void	put_padding(int len, char c, int *count);
void	print_number(int nbr, int precision, int *count);
int		unsigned_conversion(va_list args, int *flags, int *width_precision);
int		hexadecimal_conversion(char c, va_list args, int *flags,
			int *width_precision);
int		print_hex(unsigned int num, char c);
int		count_digits_hex(unsigned int nbr);
#endif