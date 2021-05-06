#include "includes/ft_printf.h"

static char	*alloc_nb(long long int n)
{
	char	*numb;
	int		size;

	size = base10(n) + 1;
	if (n < 0)
	{
		numb = (char *)malloc(sizeof(char) * size + 1);
		if (!numb)
			return (NULL);
		numb[0] = '-';
	}
	else
	{
		numb = (char *)malloc(sizeof(char) * size);
		if (!numb)
			return (NULL);
	}
	return (numb);
}

static	char	*rempl_tab(long long int n, char *numb)
{
	int				i;
	unsigned int	nb;

	i = base10(n);
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	numb[i] = '\0';
	i--;
	while (numb[i] != '-' && i >= 0)
	{
		numb[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (numb);
}

char	*new_itoa(long long int n)
{
	char		*numb;

	if (n == 0)
		return (ft_strdup(""));
	numb = alloc_nb(n);
	if (!numb)
		return (NULL);
	else
		numb = rempl_tab(n, numb);
	return (numb);
}
