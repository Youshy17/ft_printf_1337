/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hamr <yel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:38:35 by yel-hamr          #+#    #+#             */
/*   Updated: 2024/12/05 16:25:32 by yel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;
	int	y;

	x = ft_printf("%c", 'c');
	printf("\n");
	y = printf("%c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%c", 0);
	printf("\n");
	y = printf("%c", 0);
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%5c", 'c');
	printf("\n");
	y = printf("%5c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%-5c", 'c');
	printf("\n");
	y = printf("%-5c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%05c", 'c');
	printf("\n");
	y = printf("%05c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%05.5c", 'c');
	printf("\n");
	y = printf("%05.5c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("%+5c", 'c');
	printf("\n");
	y = printf("%+5c", 'c');
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");

	x = ft_printf("");
	printf("\n");
	y = printf("");
	printf("\nmine returned %d and original returned %d", x, y);
	printf("\n -------------- new test ------------------\n");
}

