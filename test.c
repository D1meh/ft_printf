#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	printf("vrai : %*.3s %.3s",10, "123", "4567");
	ft_printf("moi  : %*.3s %.3s", 10, "123", "4567");
}

//printf("minus = %d\ndot = %d\nzero = %d\nnb1 = %d\nnb2 = %d\n", prt->minus, prt->dot, prt->zero, prt->nb1, prt->nb2);
