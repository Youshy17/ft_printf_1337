/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:38:35 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/06 12:42:52 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;
	int	y;

	int s = 5;
	int *p = &s;
	x = ft_printf("%%%PPPP");
	printf("\n");
	y = printf("%%%PPPP");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

}

