/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:15:17 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/11/24 11:14:26 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINT_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int     process_flag(const char *format, int *flags, int *width_precision);
void	process_conversions(char c, va_list args, int *flags, int *width_precision);
void	character_conversion(va_list args, int *flags, int *width_precision);
void	string_conversion(va_list args, int *flags, int *width_precision);
void	pointer_conversion(va_list args, int *flags, int *width_precision);
void	integer_conversion(va_list args, int *flags, int *width_precision);
void	unsigned_conversion(va_list args, int *flags, int *width_precision);
void	hexadecimal_conversion(char c, va_list args, int *flags, int *width_precision);

#endif