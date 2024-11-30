#include "ft_printf.h"

int main ()
{
	// int a = 5;
	// int *b = &a;
	int x = ft_printf("%");
	printf("\n");
	int y = printf("%");
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

int y = printf("|%.-5d|\n",10);
*/
