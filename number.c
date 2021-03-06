#include "includes/ft_printf.h"

int	base10(long long int n)
{
	int	base;

	if (n == 0)
		return (1);
	base = 0;
	while (n != 0)
	{
		n /= 10;
		base++;
	}
	return (base);
}

int	absolute(int a, t_print *prt, int n)
{
	if (a < 0)
	{
		prt->min_pos = 1 + prt->dot;
		prt->minus++;
		if (n % 2 == 1)
			prt->is_neg1 = 1;
		else
			prt->is_neg2 = 1;
		return (-a);
	}
	return (a);
}

long long int	new_atoi(char *str, int *i)
{
	long long int	nb;

	nb = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb * 10 + str[*i] - '0';
		*i = *i + 1;
	}
	return (nb);
}

void	ft_putnbr(long long int n, t_print *prt)
{
	long long int	nb;

	nb = n;
	if (nb == 0 && prt->minus && prt->nb1 && !prt->nb2)
	{
		while (prt->nb1--)
			ft_putchar(' ', prt);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', prt);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, prt);
		ft_putchar((nb % 10) + '0', prt);
	}
	else
		ft_putchar(nb + '0', prt);
}
