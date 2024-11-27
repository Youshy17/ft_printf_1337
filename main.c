#include "ft_printf.h"

int main ()
{
	int a = 5;
	int *b = &a;
	int x = ft_printf("This is a test |%i|\n",-3);
	int y = printf("This is a test |%i|\n",-3);
	printf("mine returned %d and original returned %d\n", x, y);
}

/*
int main ()
{
	ft_printf("This is a test |%-15.15d|\n",255);
	printf("This is a test |%-15.15d|\n",255);
}

("%.6i", -3)
*/