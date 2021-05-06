#include "includes/ft_printf.h"

static void	put_double2(t_print *prt, char c, char *s, int i)
{
	if ((c != 'x' && c != 'X') || prt->nb2
		|| ft_strncmp(s, "0", ft_strlen(s)) != 0)
		ft_putstr(s + i, prt);
	else
		ft_putchar(' ', prt);
	free(s);
}

void	put_doubleD(t_print *prt, char *s, char c)
{
	int	zeros;
	int	spaces;
	int	i;
	int	n;

	i = 0;
	if (s[0] == '-')
		i++;
	n = -1;
	if (c == 'u' || c == 'x' || c == 'X'
		|| (ft_strlen(s) < 3 && ft_strncmp(s, "-1", ft_strlen(s)) != 0))
		n = 0;
	zeros = prt->nb2 - ft_strlen(s);
	spaces = prt->nb1 - max(zeros, n) - ft_strlen(s) - i;
	while (spaces-- > 0)
		ft_putchar(' ', prt);
	if (s[0] == '-')
	{
		zeros++;
		ft_putchar('-', prt);
	}
	while (zeros-- > 0)
		ft_putchar('0', prt);
	put_double2(prt, c, s, i);
}

void	flag_doubleD(t_print *prt, va_list args, char c)
{
	char	*s;
	int		zeros;

	if (c == 's')
	{
		s = ft_substr(va_arg(args, char *), 0, prt->nb2);
		zeros = 0;
		while (zeros++ < prt->nb1 - (int)ft_strlen(s))
			ft_putchar(' ', prt);
		ft_put_and_free(s, prt, c);
		return ;
	}
	else if (c == 'd' || c == 'i')
		s = new_itoa(va_arg(args, int));
	else if (c == 'u')
		s = new_itoa(va_arg(args, unsigned int));
	else
	{
		if (c == 'x')
			s = itoh(va_arg(args, unsigned int), 0);
		else
			s = itoh(va_arg(args, unsigned int), 1);
	}
	put_doubleD(prt, s, c);
}
