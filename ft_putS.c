#include "includes/ft_printf.h"

void	precNUL(va_list args, t_print *prt)
{
	va_arg(args, char *);
	while (prt->nb1-- > 0)
		ft_putchar(' ', prt);
}

void	putspaces(char c, va_list args, t_print *prt)
{
	char	*s;
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	if (c == 'p')
	{
		s = itoh(va_arg(args, long long), 0);
		spaces = 2;
	}
	if (c == 's')
		s = ft_strdup(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_itoa(va_arg(args, unsigned int));
	else if (c == 'x')
		s = itoh(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		s = itoh(va_arg(args, unsigned int), 1);
	while (i++ < prt->nb1 - (int)ft_strlen(s) - spaces)
		ft_putchar(' ', prt);
	ft_put_and_free(s, prt, c);
}

void	flag_MD(va_list args, t_print *prt, char c)
{
	char	*s;
	int		spaces;
	char	*tmp;

	if (c == 'd' || c == 'i')
		return (flag_MD_int(args, prt));
	if (c == 'u')
		return (flag_MD_u(args, prt));
	if (c == 'x' || c == 'X')
		return (flag_MD_x(args, prt, c));
	tmp = va_arg(args, char *);
	if (!tmp && prt->nb1)
		s = ft_substr("(null)", 0, prt->nb2);
	else if (!tmp)
		s = ft_strdup("(null)");
	else
		s = ft_substr(tmp, 0, prt->nb2);
	spaces = 0;
	ft_putstr(s, prt);
	while (spaces++ < prt->nb1 - (int)ft_strlen(s))
		ft_putchar(' ', prt);
	free(s);
}

void	flag_2MD_s(va_list args, t_print *prt)
{
	char	*s;
	int		spaces;

	s = va_arg(args, char *);
	ft_putstr(s, prt);
	spaces = 0;
	while (spaces++ < prt->nb1 - (int)ft_strlen(s))
		ft_putchar(' ', prt);
}
