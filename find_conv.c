#include "includes/ft_printf.h"

int	is_conv(char l)
{
	if (l != 'c' && l != 's' && l != 'p' && l != 'd' && l != 'i'
		&& l != 'u' && l != 'x' && l != 'X' && l != '%')
		return (0);
	return (1);
}

static int	conv_index(const char *str, int *i)
{
	*i = *i + 1;
	while (str[*i] && !is_conv(str[*i]))
		*i = *i + 1;
	return (*i);
}

int	find_conv(const char *str, va_list args, int *i, t_print *prt)
{
	int		tmp;
	char	*flags;

	tmp = *i;
	conv_index(str, i);
	flags = ft_substr(str, tmp + 1, *i - tmp);
	if (ft_strlen(flags) > 1)
	{
		getFlag(flags, prt, args);
		redirect_flag(prt, args, flags);
	}
	else
		redirect(flags, args, prt);
	free(flags);
	return (1);
}
