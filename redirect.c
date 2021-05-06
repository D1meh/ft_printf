#include "includes/ft_printf.h"

static int	is_int(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

static int	is_hexa(char c)
{
	if (c == 'p' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	redirect(char *flags, va_list args, t_print *prt)
{
	char	c;

	c = flags[ft_strlen(flags) - 1];
	if (c == '%')
		ft_putchar('%', prt);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), prt);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), prt);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), prt);
	else if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), prt);
	else if (c == 'x')
		put_itoh(va_arg(args, unsigned int), 0, prt);
	else if (c == 'X')
		put_itoh(va_arg(args, unsigned int), 1, prt);
	else if (c == 'p')
		ft_putP(va_arg(args, unsigned long), prt);
}

void	redirect_f2(t_print *prt, va_list args, char c)
{
	if (prt->minus && (is_int(c) || c == 'u'))
		flag_minus_int(prt, args, c);
	else if (prt->minus && (is_hexa(c)))
		flag_minus_x(prt, args, c);
	else if (prt->minus)
		flag_minus(prt, args, c);
	else if (!prt->minus && !prt->dot && !prt->zero)
		putspaces(c, args, prt);
	else if (!prt->nb2 && prt->dot && prt->nb1
		&& (c == 's' || is_int(c) || c == 'u'))
		precNUL(args, prt);
	else if (c == 's' && prt->dot)
		ft_putnstr(va_arg(args, char *), prt, prt->nb2);
	else if (prt->zero || (c != 'c' && c != 's'
			&& c != 'p' && prt->dot && !prt->nb1))
		flag_zero(prt, args, c);
}

void	redirect_flag(t_print *prt, va_list args, char *flags)
{
	char	c;

	c = flags[ft_strlen(flags) - 1];
	if ((!prt->minus && !prt->dot && !prt->zero) && c == 'c')
		flag_number(prt, args, flags);
	else if (prt->dot && prt->minus > 1 && prt->min_pos != 1 && is_int(c))
		flag_2MD(args, prt);
	else if (prt->dot && prt->minus > 1 && c == 's'
		&& (!prt->is_neg1 || prt->is_neg2))
		flag_2MD_s(args, prt);
	else if (prt->dot && prt->minus && prt->is_neg2 && prt->zero)
		flag_zero(prt, args, c);
	else if (prt->dot && prt->minus == 1 && prt->is_neg2)
		putspaces(c, args, prt);
	else if (prt->dot && prt->minus)
		flag_MD(args, prt, c);
	else if (prt->dot && prt->nb1 && (prt->nb2 || is_int(c)
			|| c == 'u' || is_hexa(c)))
		flag_doubleD(prt, args, c);
	else
		redirect_f2(prt, args, c);
}
