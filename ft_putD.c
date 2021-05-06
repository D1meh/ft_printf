#include "includes/ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	flag_minus_int(t_print *prt, va_list args, char c)
{
	int				i;
	char			*d;

	i = 0;
	if (c == 'u')
		d = ft_itoa(va_arg(args, unsigned int));
	else
		d = ft_itoa(va_arg(args, int));
	ft_putstr(d, prt);
	while (i++ < prt->nb2 - (int)ft_strlen(d))
		ft_putchar(' ', prt);
	free(d);
}

void	flag_MD_int(va_list args, t_print *prt)
{
	long int	d;
	int			zeros;
	int			spaces;
	int			minus;

	d = va_arg(args, int);
	minus = 0;
	if (d < 0)
	{
		ft_putchar('-', prt);
		minus = 1;
		d = -d;
	}
	zeros = 0;
	spaces = 0;
	while (zeros < prt->nb2 - base10(d))
	{
		zeros++;
		ft_putchar('0', prt);
	}
	if (d != 0 || prt->nb1 || prt->nb2)
		ft_putnbr(d, prt);
	while (spaces++ < prt->nb1 - max(base10(d), zeros + base10(d)) - minus)
		ft_putchar(' ', prt);
}

void	flag_MD_u(va_list args, t_print *prt)
{
	long int	d;
	int			zeros;
	int			spaces;
	int			minus;

	d = va_arg(args, unsigned int);
	minus = 0;
	zeros = 0;
	spaces = 0;
	while (zeros < prt->nb2 - base10(d))
	{
		zeros++;
		ft_putchar('0', prt);
	}
	if (prt->nb2 || prt->nb1 || d != 0)
		ft_putnbr(d, prt);
	while (spaces++ < prt->nb1 - max(base10(d), zeros + base10(d)) - minus)
		ft_putchar(' ', prt);
}

void	flag_2MD(va_list args, t_print *prt)
{
	long int	d;
	int			spaces;

	d = va_arg(args, int);
	spaces = 0;
	if (d < 0)
	{
		ft_putchar('-', prt);
		d = d * -1;
		spaces++;
	}
	ft_putnbr(d, prt);
	while (spaces++ < prt->nb1 - base10(d))
		ft_putchar(' ', prt);
}
