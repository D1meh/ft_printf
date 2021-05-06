#include "includes/ft_printf.h"

void	ft_putchar(char c, t_print *prt)
{
	write(1, &c, 1);
	prt->len += 1;
}
