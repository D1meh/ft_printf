#include "includes/ft_printf.h"

void	ft_putchar(char c, t_print *prt)
{
	write(1, &c, 1);
	prt->len += 1;
}

void	putzero_i(int d, t_print *prt)
{
	int	zero;

	zero = 0;
	while (zero < prt->nb1 - base10(d))
	{
		ft_putchar('0', prt);
		zero++;
	}
	ft_putnbr(d, prt);
}

void	putzero_u(unsigned int u, t_print *prt)
{
	int	zero;

	zero = 0;
	while (zero < prt->nb1 - base10(u))
	{
		ft_putchar('0', prt);
		zero++;
	}
	ft_putnbr(u, prt);
}

void	putzero_x(char *x, t_print *prt)
{
	int	zero;

	zero = 0;
	while (zero < prt->nb1 - (int)ft_strlen(x))
	{
		ft_putchar('0', prt);
		zero++;
	}
	ft_putstr(x, prt);
}
