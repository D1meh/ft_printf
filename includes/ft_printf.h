#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
#include <stdio.h>

typedef struct s_print
{
	int	len;
	int	dot;
	int	minus;
	int	zero;
	int	nb1;
	int	nb2;
}	t_print;

int				ft_printf(const char *str, ...);
int				base10(long long int n);
void			ft_putchar(char c, t_print *prt);
void			ft_putnbr(long long int n, t_print *prt);
void			ft_putstr(char *s, t_print *prt);
int				find_conv(const char *str, va_list args, int *i, t_print *prt);
char			*upper(char *str);
char			*lower(char *str);
char			*itoh(long long int n, int maj);
void			ft_putP(long long ptr, t_print *prt);
void			init_struct(t_print *prt);
void			redirect(char *flags, va_list args, t_print *prt);
long long int	new_atoi(char *str, int *i);
int				is_conv(char l);
int				getFlag(char *flags, t_print *prt, va_list args);
int				check_error(char *flags, t_print *prt);
void			put_itoh(long long n, int maj, t_print *prt);
void			putzero_i(int d, t_print *prt);
void			putzero_u(unsigned int u, t_print *prt);
void			putzero_x(char *x, t_print *prt);
void			redirect_flag(t_print *prt, va_list args, char *flags);
void			ft_putnstr(char *s, t_print *prt, int n);
void			put_doubleD(t_print *prt, char *s);
int				absolute(int a, t_print *prt);
char			*putspaces(char c, va_list args, t_print *prt);

#endif
