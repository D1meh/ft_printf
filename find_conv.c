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

static int	is_flag(char *flags)
{
	int	i;

	i = 0;
	if (flags[i] == '*')
		i++;
	else
	{
		while (flags[i] && ft_isdigit(flags[i]))
			i++;
	}
	if (is_conv(flags[i]))
		return (1);
	if (flags[i] == '.' || flags[i] == '-')
		i++;
	if (flags[i] == '*' && flags[i - 1] != '*')
		i++;
	else
	{
		while (flags[i] && ft_isdigit(flags[i]))
			i++;
	}
	if (is_conv(flags[i]))
		return (1);
	return (0);
}

int	find_conv(const char *str, va_list args, int *i, t_print *prt)
{
	int		tmp;
	char	*flags;

	tmp = *i;
	conv_index(str, i);
	flags = ft_substr(str, tmp + 1, *i - tmp);
	if (!is_flag(flags))
	{
		free(flags);
		return (-1);
	}
	if (ft_strlen(flags) > 1)
	{
		tmp = getFlag(flags, prt, args);
		if (tmp == -1 || check_error(flags, prt) == -1)
			return (-1);
		redirect_flag(prt, args, flags);
	}
	else
		redirect(flags, args, prt);
	free(flags);
	return (1);
}
