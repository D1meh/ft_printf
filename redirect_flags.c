#include "includes/ft_printf.h"

void	flag_number(t_print *prt, va_list args, char *flags)
{
	int		i;

	i = 0;
	if (prt->nb1)
	{
		while (++i < prt->nb1)
			ft_putchar(' ', prt);
	}
	else
	{
		while (++i < prt->nb2)
			ft_putchar(' ', prt);
	}
	redirect(flags, args, prt);
}

void	flag_zero(t_print *prt, va_list args, char c)
{
	char	*s;

	if (c == 'd' || c == 'i')
		putzero_i(va_arg(args, int), prt);
	else if (c == 'u')
		putzero_u(va_arg(args, unsigned int), prt);
	else
	{
		if (c == 'x')
			s = itoh(va_arg(args, unsigned int), 0);
		else
			s = itoh(va_arg(args, unsigned int), 1);
		putzero_x(s, prt);
		free(s);
	}
}

void	flag_minus(t_print *prt, va_list args, char c)
{
	int		i;
	char	*s;

	i = 0;
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int), prt);
		if (prt->nb1)
		{
			while (i++ < prt->nb1 - 1)
				ft_putchar(' ', prt);
		}
		else
		{
			while (i++ < prt->nb2 - 1)
				ft_putchar(' ', prt);
		}
		return ;
	}
	s = va_arg(args, char *);
	ft_putstr(s, prt);
	while (i++ < prt->nb2 - (int)ft_strlen(s))
		ft_putchar(' ', prt);
}
