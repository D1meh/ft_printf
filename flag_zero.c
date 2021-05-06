#include "includes/ft_printf.h"

static void	putzero_i2(int i, t_print *prt, int zero)
{
	while (zero < prt->nb1 - base10(i))
	{
		ft_putchar('0', prt);
		zero++;
	}
	if (i == INT_MIN)
		ft_putstr("2147483648", prt);
	else if (i != 0 || prt->nb1 || (i == 0
			&& ((prt->zero && !prt->dot) || (prt->dot && prt->nb2))))
		ft_putnbr(i, prt);
}

void	putzero_i(int d, t_print *prt)
{
	int			zero;
	long int	i;

	zero = 0;
	if (d < 0)
	{
		zero++;
		ft_putchar('-', prt);
		i = d * -1;
	}
	else
		i = d;
	if (!prt->nb1 && prt->nb2)
	{
		zero = 0;
		if (prt->is_neg2)
			prt->nb1 = 1;
		else
			prt->nb1 = prt->nb2;
	}
	putzero_i2(i, prt, zero);
}

void	putzero_u(unsigned int u, t_print *prt)
{
	int	zero;

	zero = 0;
	if (!prt->nb1 && prt->nb2)
		prt->nb1 = prt->nb2;
	if (u == 0 && !prt->nb1 && (prt->nb2 || (prt->zero && !prt->dot)))
		prt->nb1++;
	if (u == 0)
		prt->nb1++;
	while (zero < prt->nb1 - base10(u))
	{
		ft_putchar('0', prt);
		zero++;
	}
	if (u != 0)
		ft_putnbr(u, prt);
}

void	putzero_x(char *x, t_print *prt)
{
	int	zero;

	zero = 0;
	if (!prt->nb1 && prt->nb2)
		prt->nb1 = prt->nb2;
	if (ft_strncmp(x, "0", ft_strlen(x)) == 0
		&& !prt->nb1 && (prt->nb2 || (prt->zero && !prt->dot)))
		prt->nb1++;
	if (ft_strncmp(x, "0", ft_strlen(x)) == 0)
		prt->nb1++;
	while (zero < prt->nb1 - (int)ft_strlen(x))
	{
		ft_putchar('0', prt);
		zero++;
	}
	if (ft_strncmp(x, "0", ft_strlen(x)) != 0)
		ft_putstr(x, prt);
}
