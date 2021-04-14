#include "includes/ft_printf.h"
#include <stdio.h>

static void	flag_number(t_print *prt, va_list args, char *flags)
{
	int		i;

	i = 0;
	while (++i < prt->nb1)
		ft_putchar(' ', prt);
	redirect(flags, args, prt);
}

static void	flag_zero(t_print *prt, va_list args, char c)
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

static void	flag_minus(t_print *prt, va_list args)
{
	int		i;
	char	*s;

	s = va_arg(args, char *);
	ft_putstr(s, prt);
	i = 0;
	while (i < prt->nb2 - (int)ft_strlen(s))
	{
		ft_putchar(' ', prt);
		i++;
	}
}

static void	flag_doubleD(t_print *prt, va_list args, char c)
{
	char	*s;
	int		zeros;

	if (c == 's')
	{
		s = ft_substr(va_arg(args, char *), 0, prt->nb2);
		zeros = 0;
		while (zeros++ < prt->nb1 - (int)ft_strlen(s))
			ft_putchar('0', prt);
		free(s);
		return ;
	}
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_itoa(va_arg(args, unsigned int));
	else
	{
		if (c == 'x')
			s = itoh(va_arg(args, unsigned int), 0);
		else
			s = itoh(va_arg(args, unsigned int), 1);
	}
	put_doubleD(prt, s);
}

void	redirect_flag(t_print *prt, va_list args, char *flags)
{
	char	c;

	c = flags[ft_strlen(flags) - 1];
	if ((!prt->minus && !prt->dot && !prt->zero)
		|| (prt->dot && prt->nb1 && !prt->nb2))
		flag_number(prt, args, flags);
	else if (prt->zero || (c != 'c' && c != 's'
			&& c != 'p' && prt->dot && !prt->nb1))
		flag_zero(prt, args, c);
	else if (c == 's' && prt->dot && prt->nb2 && !prt->nb1)
		ft_putnstr(va_arg(args, char *), prt, prt->nb2);
	else if (prt->minus)
		flag_minus(prt, args);
	else if (prt->dot && prt->nb1 && prt->nb2)
		flag_doubleD(prt, args, c);
}
