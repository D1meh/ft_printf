#include "includes/ft_printf.h"

void	ft_put_if(char *d, t_print *prt, char c, int a)
{
	if ((c != 'x' && c != 'X') || ft_strncmp(d, "0", ft_strlen(d)) != 0)
		ft_putstr(d, prt);
	else if (a)
	{
		while (prt->nb1--)
			ft_putchar(' ', prt);
	}
	else if (c == 'x' || c == 'X')
		ft_putchar(' ', prt);
}

void	flag_MD_x(va_list args, t_print *prt, char c)
{
	char	*d;
	int		zeros;
	int		spaces;

	if (c == 'x')
		d = itoh(va_arg(args, unsigned int), 0);
	else
		d = itoh(va_arg(args, unsigned int), 1);
	zeros = 0;
	spaces = 0;
	while (zeros < prt->nb2 - (int)ft_strlen(d))
	{
		zeros++;
		ft_putchar('0', prt);
	}
	if (prt->nb2 || ft_strncmp(d, "0", ft_strlen(d)) != 0)
		ft_putstr(d, prt);
	else if (prt->nb1)
		ft_putchar(' ', prt);
	while (spaces++ < prt->nb1
		- max((int)ft_strlen(d), zeros + (int)ft_strlen(d)))
		ft_putchar(' ', prt);
	free(d);
}

void	flag_minus_x(t_print *prt, va_list args, char c)
{
	int				i;
	char			*d;

	i = 0;
	if (c == 'x')
		d = itoh(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		d = itoh(va_arg(args, unsigned int), 1);
	else
	{
		ft_putstr("0x", prt);
		d = itoh(va_arg(args, long long), 0);
		i = 2;
	}
	ft_putstr(d, prt);
	while (i++ < prt->nb2 - (int)ft_strlen(d))
		ft_putchar(' ', prt);
	free(d);
}
