/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:38:35 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/04 15:17:32 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;
	int	y;

	// int a = 5;
	// int *b = &a;
	x = ft_printf(" %#d ", 3);
	printf("\n");
	y = printf(" %q ", 3);
	printf("\n");
	printf("mine returned %d and original returned %d\n", x, y);
}

/*
int main ()
{
	ft_printf("%.6i",-3);
	printf("%.6i",-3);
	ft_printf("|%-15.15d|\n",255);
	printf("|%-15.15d|\n",255);
}

int	y = printf("|%.-5d|\n",10);
*/
