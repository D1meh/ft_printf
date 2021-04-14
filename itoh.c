#include "includes/ft_printf.h"

static int	base16(long int nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb != 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

static char	*alloc_nb(long long int nb, char *hexa)
{
	int		count;
	int		i;
	char	*n;

	count = base16(nb);
	n = malloc(sizeof(char) * count);
	if (!n)
		return (NULL);
	n[count] = 0;
	i = count - 1;
	if (nb < 0)
	{
		n[0] = '-';
		nb = -nb;
	}
	while (nb != 0 && n[i] != '-' && i >= 0)
	{
		n[i] = hexa[nb % 16];
		i--;
		nb /= 16;
	}
	return (n);
}

static char	*change_a(char *a, int maj)
{
	if (maj)
		a = upper(a);
	else
		a = lower(a);
	return (a);
}

char	*itoh(long long n, int maj)
{
	static char		a[16] = "0123456789abcdef";
	long long int	nb;
	char			*hexa;

	nb = n;
	change_a(a, maj);
	hexa = alloc_nb(nb, a);
	return (hexa);
}

void	put_itoh(long long n, int maj, t_print *prt)
{
	char	*s;

	s = itoh(n, maj);
	ft_putstr(s, prt);
	free(s);
}
